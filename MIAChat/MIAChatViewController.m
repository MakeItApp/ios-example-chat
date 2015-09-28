//
//  MIAChatViewController.m
//  MIAChat
//
//  Created by Jacopo Giola on 03/04/15.
//  Copyright (c) 2015 MIA Srl. All rights reserved.
//

#import "MIAChatViewController.h"
#import "MIAImageViewController.h"
// Views
#import "MIAChatTableViewCell.h"
#import "AppDelegate.h"
#import <mkApp/mkApp.h>

#import "UIImageView+MIASDK.h"

NSString *const kRemoteNotificationReceived = @"eu.makeitapp.demo.remotenotificationreceived";

static void *TextFieldContext = &TextFieldContext;

@interface MIAChatViewController () <UITableViewDelegate, UITableViewDataSource, UITextViewDelegate, UIImagePickerControllerDelegate, UINavigationControllerDelegate, MKLoginDelegate>

@property (nonatomic, weak) IBOutlet UITableView *tableView;
@property (nonatomic, weak) IBOutlet UITextView *textView;
@property (nonatomic, weak) IBOutlet UIButton *sendButton;
@property (nonatomic, weak) IBOutlet UIView *bottomBar;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *bottomConstraint;
@property (nonatomic, weak) IBOutlet NSLayoutConstraint *textViewHeightConstraint;

@property (nonatomic, strong) NSArray *messages;
@property (atomic) BOOL fetching;

@end

@implementation MIAChatViewController

#pragma mark - View Life Cycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.title = NSLocalizedString(@"Chat", nil);
    self.tableView.rowHeight = UITableViewAutomaticDimension;
    self.tableView.estimatedRowHeight = 72.0f;
    self.sendButton.enabled = NO;

    [self.textView addObserver:self forKeyPath:NSStringFromSelector(@selector(contentSize)) options:NSKeyValueObservingOptionNew context:TextFieldContext];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillShowNotification:) name:UIKeyboardWillShowNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(keyboardWillHideNotification:) name:UIKeyboardWillHideNotification object:nil];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(receivedPushNotification:) name:kRemoteNotificationReceived object:nil];

    self.fetching = YES;
    if (![[MKAppInstance sharedInstance] getLoggedUser]) {
        [self openLoginViewControllerAnimated:YES];
    }
}

- (void)dealloc
{
    _textView.delegate = nil;
    _tableView.scrollEnabled = NO;
    _tableView.delegate = nil;
    _tableView.dataSource = nil;
    [_textView removeObserver:self forKeyPath:NSStringFromSelector(@selector(contentSize)) context:TextFieldContext];
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    if (!self.fetching) {
        [self loadContentAnimated:NO];
    }
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString:@"ShowImage"]) {
        MIAImageViewController *ivc = segue.destinationViewController;
        ivc.image = sender;
    }
}

#pragma mark - NSObject

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    if (context == TextFieldContext && [keyPath isEqualToString:NSStringFromSelector(@selector(contentSize))]) {
        CGSize textViewContentSize = [change[@"new"] CGSizeValue];
        CGFloat contentHeight = textViewContentSize.height;

        CGFloat minHeight = 0.0f;
        if (contentHeight < minHeight) {
            contentHeight = minHeight;
        }

        CGFloat actualHeight = self.textViewHeightConstraint.constant;
        if (actualHeight == contentHeight) {
            return;
        }

        if (!self.bottomBar) {
            return;
        }

        CGFloat oldBarHeight = CGRectGetHeight(self.bottomBar.frame);
        self.textViewHeightConstraint.constant = contentHeight;
        [self.bottomBar layoutIfNeeded];
        CGFloat newBarHeight = CGRectGetHeight(self.bottomBar.frame);
        CGPoint newOffset = self.tableView.contentOffset;
        newOffset.y += (newBarHeight - oldBarHeight);
        self.tableView.contentOffset = newOffset;
        return;
    }

    [super observeValueForKeyPath:keyPath ofObject:object change:change context:context];
}

#pragma mark - Notifications

- (void)keyboardWillShowNotification:(NSNotification *)notification
{
    NSDictionary *userInfo = notification.userInfo;
    CGRect endFrame = [userInfo[UIKeyboardFrameEndUserInfoKey] CGRectValue];
    NSTimeInterval duration = [userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
    NSUInteger curve =  [userInfo[UIKeyboardAnimationCurveUserInfoKey] unsignedIntegerValue];

    CGFloat keyboardHeight = CGRectGetHeight(endFrame);
    self.bottomConstraint.constant = keyboardHeight;

    [UIView animateKeyframesWithDuration:duration delay:0.0 options:curve animations:^{
        [self.view layoutIfNeeded];
    } completion:^(BOOL finished) {
        [self scrollTableToBottomAnimated:YES];
    }];
}

- (void)keyboardWillHideNotification:(NSNotification *)notification
{
    NSDictionary *userInfo = notification.userInfo;
    NSTimeInterval duration = [userInfo[UIKeyboardAnimationDurationUserInfoKey] doubleValue];
    NSUInteger curve =  [userInfo[UIKeyboardAnimationCurveUserInfoKey] unsignedIntegerValue];

    self.bottomConstraint.constant = 0.0f;
    [UIView animateKeyframesWithDuration:duration delay:0.0 options:curve animations:^{
        [self.view layoutIfNeeded];
    } completion:NULL];
}

- (void)receivedPushNotification:(NSNotification *)notification
{
    if (self.fetching) {
        return;
    }

    [self loadContentAnimated:YES];
}

#pragma mark - Private API

- (void)loadContentAnimated:(BOOL)animated
{
    self.fetching = YES;
    MKQuery *query = [MKQuery queryWithcollectionName:@"chatmessage"];
    query.limit = 30;
    [query orderDescendingByCreationDate];

    __weak typeof(self)weakSelf = self;
    [query findAllInBackgroundWithBlock:^(NSArray *results, NSError *error) {
        __strong typeof(weakSelf)strongSelf = weakSelf;
        if (!strongSelf) {
            return;
        }

        if (error) {
            [strongSelf showErrorAlertView];
            return;
        }

        strongSelf.messages = [results sortedArrayUsingDescriptors:@[[NSSortDescriptor sortDescriptorWithKey:@"createdAt" ascending:YES]]];
        dispatch_async(dispatch_get_main_queue(), ^{
            [strongSelf updateTableViewAnimated:animated];
        });
        self.fetching = NO;
    }];
}

- (void)updateTableViewAnimated:(BOOL)animated
{
    self.tableView.hidden = NO;
    [self.tableView reloadData];
    [self scrollTableToBottomAnimated:animated];
}

- (void)scrollTableToBottomAnimated:(BOOL)animated
{
    if (self.messages.count > 0) {
        NSIndexPath *indexPath = [NSIndexPath indexPathForRow:(self.messages.count - 1) inSection:0];
        [self.tableView scrollToRowAtIndexPath:indexPath atScrollPosition:UITableViewScrollPositionBottom animated:animated];
    }
}

- (NSCharacterSet *)characterSet
{
    static NSCharacterSet *set = nil;
    if (!set) {
        set = [NSCharacterSet whitespaceAndNewlineCharacterSet];
    }
    return set;
}

- (void)showErrorAlertView
{
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"Error", nil)
                                                                   message:NSLocalizedString(@"Connection Error", nil)
                                                            preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"Ok", nil) style:UIAlertActionStyleCancel handler:NULL]];
    [self presentViewController:alert animated:YES completion:NULL];
}

- (void)openCamera
{
    UIImagePickerController *ipc = [[UIImagePickerController alloc] init];
    ipc.delegate = self;
    ipc.sourceType = UIImagePickerControllerSourceTypeCamera;
    [self presentViewController:ipc animated:YES completion:NULL];
}

- (void)openLibrary
{
    UIImagePickerController *ipc = [[UIImagePickerController alloc] init];
    ipc.delegate = self;
    ipc.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    [self presentViewController:ipc animated:YES completion:NULL];
}

- (void)uploadImage:(UIImage *)image
{
    NSData *JPGData = UIImageJPEGRepresentation(image, 0.8);
    NSString *fileName = [NSUUID UUID].UUIDString;
    MKCollectionFile *file = [MKCollectionFile fileWithName:fileName data:JPGData];
    [file saveInBackgroundWithBlock:^(MKCollection *collection, NSError *error) {
        if (error) {
            UIAlertController *alert = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"Saving Error", nil)
                                                                           message:NSLocalizedString(@"Saving Failed", nil)
                                                                    preferredStyle:UIAlertControllerStyleAlert];
            [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"Ok", nil) style:UIAlertActionStyleCancel handler:NULL]];
            [self presentViewController:alert animated:YES completion:NULL];
            return;
        }

        MKCollection *message = [MKCollection collectionWithName:@"chatmessage"];
        MKUser *user = [[MKAppInstance sharedInstance] getLoggedUser];
        [message setObject:user.userName forKey:@"alias"];
        [message setObject:collection.collectionId forKey:@"messageAttachment"];
        [UIImageView mia_cacheImage:image forCollectionId:collection.collectionId];

        [message saveInBackgroundWithBlock:^(MKCollection *collection2, NSError *saveError) {
            if (saveError) {
                UIAlertController *alert = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"Saving Error", nil)
                                                                               message:NSLocalizedString(@"Saving Failed", nil)
                                                                        preferredStyle:UIAlertControllerStyleAlert];
                [alert addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"Ok", nil) style:UIAlertActionStyleCancel handler:NULL]];
                [self presentViewController:alert animated:YES completion:NULL];
                return;
            }
            self.messages = [self.messages arrayByAddingObject:message];
            [self updateTableViewAnimated:YES];
        }];
    }];
}

- (void)openLoginViewControllerAnimated:(BOOL)animated
{
    MKLoginViewController *lvc = [[MKLoginViewController alloc] initWithDelegate:self];
    [self presentViewController:lvc animated:animated completion:NULL];
}

#pragma mark - UIAction

- (IBAction)sendButtonPressed:(id)sender
{
    self.sendButton.enabled = NO;
    NSString *text = [self.textView.text stringByTrimmingCharactersInSet:[self characterSet]];
    self.textView.text = @"";

    MKUser *user = [[MKAppInstance sharedInstance] getLoggedUser];
    MKCollection *newText = [MKCollection collectionWithName:@"chatmessage"];
    [newText setObject:text forKey:@"message"];
    [newText setObject:user.userName forKey:@"alias"];

    [newText saveInBackgroundWithBlock:^(MKCollection *collection, NSError *error) {
        self.messages = [self.messages arrayByAddingObject:newText];
        [self updateTableViewAnimated:YES];
    }];
}

- (IBAction)sendPhotoButtonPressed:(id)sender
{
    UIAlertController *actions = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"Choose Photo", nil) message:@"" preferredStyle:UIAlertControllerStyleActionSheet];
    if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypeCamera]) {
        [actions addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"Camera", nil) style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
            [self openCamera];
        }]];
    }

    if ([UIImagePickerController isSourceTypeAvailable:UIImagePickerControllerSourceTypePhotoLibrary]) {
        [actions addAction:[UIAlertAction actionWithTitle:NSLocalizedString(@"Camera Roll", nil) style:UIAlertActionStyleDefault handler:^(UIAlertAction *action) {
            [self openLibrary];
        }]];
    }

    [self presentViewController:actions animated:YES completion:NULL];
}

#pragma mark - Delegate
#pragma mark UIScrollViewDelegate

- (BOOL)scrollViewShouldScrollToTop:(UIScrollView *)scrollView
{
    if ([scrollView isEqual:self.tableView]) {
        return YES;
    }

    return NO;
}

#pragma mark UITextViewDelegate

- (BOOL)textView:(UITextView *)textView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text
{
    NSString *newText = [textView.text stringByReplacingCharactersInRange:range withString:text];
    [newText stringByTrimmingCharactersInSet:[self characterSet]];
    self.sendButton.enabled = (newText.length > 0);

    return YES;
}

#pragma mark UIImagePickerControllerDelegate

- (void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    [self dismissViewControllerAnimated:YES completion:NULL];
}

- (void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary *)info
{
    UIImage *image = info[UIImagePickerControllerOriginalImage];
    [self uploadImage:image];

    [self dismissViewControllerAnimated:YES completion:NULL];
}

#pragma mark UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    MIAChatTableViewCell *cell = (id)[tableView cellForRowAtIndexPath:indexPath];

    NSString *identifier = cell.reuseIdentifier;
    if ([identifier isEqualToString:@"PlayerImageCell"]
        || [identifier isEqualToString:@"OpponentImageCell"]) {
        [self performSegueWithIdentifier:@"ShowImage" sender:cell.attachmentImageView.image];
    }
}

#pragma mark MKLoginDelegate

#pragma mark MKLoginDelegate

- (BOOL)loginViewController:(MKLoginViewController *)loginController shouldBeginLoginWithUsername:(NSString *)username
{
    return YES;
}

- (void)loginViewController:(MKLoginViewController *)loginController didLogInUser:(MKUser *)user
{
    [self dismissViewControllerAnimated:YES completion:NULL];
    self.fetching = NO;
    [self updateTableViewAnimated:YES];
}

- (void)loginViewController:(MKLoginViewController *)loginController didFailLogin:(NSError *)error
{
    NSLog(@"Error %@",[error localizedDescription]);
}

- (void)loginViewControllerDidCancelLogin:(MKLoginViewController *)logInController
{
    [self dismissViewControllerAnimated:YES completion:NULL];
    [self updateTableViewAnimated:YES];
}

- (BOOL)registerViewController:(MKRegisterViewController *)registerController shouldBeginCreateUsername:(NSString *)username
{
    return YES;
}

- (void)registerViewController:(MKRegisterViewController *)registerController didCreateUser:(MKUser *)user
{
    [self dismissViewControllerAnimated:YES completion:nil];
    self.fetching = NO;
    [self updateTableViewAnimated:YES];
}

- (void)registerViewController:(MKRegisterViewController *)registerController didFailCreateUser:(NSError *)error
{
    NSLog(@"Errore: %@", [error localizedDescription]);
}

#pragma mark - Data Source
#pragma mark UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.messages.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *playerCell = @"PlayerCell";
    static NSString *opponentCell = @"OpponentCell";
    static NSString *playerImageCell = @"PlayerImageCell";
    static NSString *opponentImageCell = @"OpponentImageCell";
    MKCollection *message = self.messages[indexPath.row];
    NSString *imageCollId = [message objectForKey:@"messageAttachment"];
    if (![imageCollId isKindOfClass:[NSString class]]) {
        imageCollId = nil;
    }

    NSString *playerName = [message objectForKey:@"alias"];
    NSString *messageText = [message objectForKey:@"message"];

    BOOL isPlayerCell = NO;
    if ([message.creatorId isEqualToString:[[MKAppInstance sharedInstance] getLoggedUser].collectionId]) {
        isPlayerCell = YES;
    }

    NSString *cellID = nil;
    if (isPlayerCell) {
        if (imageCollId) {
            cellID = playerImageCell;
        } else {
            cellID = playerCell;
        }
    } else {
        if (imageCollId) {
            cellID = opponentImageCell;
        } else {
            cellID = opponentCell;
        }
    }

    MIAChatTableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:cellID forIndexPath:indexPath];
    cell.nameLabel.text = playerName;
    if (imageCollId) {
        [cell.attachmentImageView mia_setImageWithCollectionId:imageCollId placeholderImage:nil completionHandler: ^{
            [cell hideLoading];
        }];
    } else {
        [cell hideLoading];
        cell.messageLabel.text = messageText;
    }
    
    return cell;
}

@end
