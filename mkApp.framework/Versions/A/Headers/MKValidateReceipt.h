//
//  MKValidateReceipt.h
//  mkApp
//
//  Created by Mia Srl on 9/16/13.
//  Copyright (c) 2013 MakeItApp.eu. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MKCollection;
@class SKPaymentTransaction;

@interface MKValidateReceipt: NSObject

+ (void)validateTransactionReceipt:(SKPaymentTransaction *)transaction withBlock:(void(^)(MKCollection *receipt, NSError *error))block;

@end
