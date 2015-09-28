//
//  MIAImageViewController.m
//  MIAChat
//
//  Created by Jacopo Giola on 09/04/15.
//  Copyright (c) 2015 MIA Srl. All rights reserved.
//

#import "MIAImageViewController.h"

@interface MIAImageViewController ()

@property (nonatomic, strong) IBOutlet UIImageView *imageView;

@end

@implementation MIAImageViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    self.imageView.image = self.image;
}

@end
