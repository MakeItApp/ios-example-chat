//
//  MIAChatTableViewCell.h
//  MIAChat
//
//  Created by Jacopo Giola on 03/04/15.
//  Copyright (c) 2015 MIA Srl. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MIAChatTableViewCell : UITableViewCell

@property (nonatomic, strong, readonly) UIImageView *attachmentImageView;
@property (nonatomic, strong, readonly) UILabel *nameLabel;
@property (nonatomic, strong, readonly) UILabel *messageLabel;

- (void)hideLoading;

@end
