//
//  MKCollection+Subscription.h
//  MIAChat
//
//  Created by Jacopo Giola on 03/04/15.
//  Copyright (c) 2015 MIA Srl. All rights reserved.
//

#import <mkApp/mkApp.h>

@interface MKCollection (Subscription)

- (id)objectForKeyedSubscript:(NSString *)key;
- (void)setObject:(id)obj forKeyedSubscript:(NSString *)key;

@end
