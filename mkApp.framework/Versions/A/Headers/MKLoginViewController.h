//
//  LoginViewController.h
//  mkApp
//
//  Created by Francesco Soncini Sessa on 20/07/14.
//  Copyright (c) 2014 MakeItApp.eu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MKLoginDelegate.h"

@interface MKLoginViewController : UIViewController

@property (nonatomic, weak) id<MKLoginDelegate> delegate;

- (instancetype)initWithDelegate:(id<MKLoginDelegate>)delegate;

@end
