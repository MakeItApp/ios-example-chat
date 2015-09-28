//
//  MIAChatTableViewCell.m
//  MIAChat
//
//  Created by Jacopo Giola on 03/04/15.
//  Copyright (c) 2015 MIA Srl. All rights reserved.
//

#import "MIAChatTableViewCell.h"

@interface MIAChatTableViewCell ()

@property (nonatomic, strong) IBOutlet UIActivityIndicatorView *spinner;
@property (nonatomic, strong, readwrite) IBOutlet UIImageView *attachmentImageView;
@property (nonatomic, strong, readwrite) IBOutlet UILabel *nameLabel;
@property (nonatomic, strong, readwrite) IBOutlet UILabel *messageLabel;

@end

@implementation MIAChatTableViewCell

- (void)prepareForReuse
{
    self.messageLabel.text = @"";
    self.attachmentImageView.image = nil;
    [self.spinner startAnimating];
}

- (void)hideLoading
{
    [self.spinner stopAnimating];
}

@end
