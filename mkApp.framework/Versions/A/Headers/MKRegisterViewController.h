//
//  RegisterViewController.h
//  mkApp
//
//  Created by Francesco Soncini Sessa on 20/07/14.
//  Copyright (c) 2014 MakeItApp.eu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MKLoginDelegate.h"

@interface MKRegisterViewController : UIViewController

@property (nonatomic, weak) id<MKLoginDelegate> delegate;

- (id)initWithDelegate:(id<MKLoginDelegate>)delegate;

@end
