//
//  MKNetworkActivity.h
//  mkApp
//
//  Created by FSS
//  Copyright (c) 2012 makeitapp.eu All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 Helper class for displaying the network activity indicator
 */
@interface MKNetworkActivity : NSObject

/**
 Begin a network activity.

 Must be balanced with <end>.
 */
+ (void)begin;

/**
 End a network activity.

 Must be balanced with <begin>.
 */
+ (void)end;

/**
 Returns the number of current network activities
 @return The number of current network activities
 */
+ (NSInteger)activityCount;

@end
