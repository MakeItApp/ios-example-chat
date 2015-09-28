//
//  MKCollection+Subscription.m
//  MIAChat
//
//  Created by Jacopo Giola on 03/04/15.
//  Copyright (c) 2015 MIA Srl. All rights reserved.
//

#import "MKCollection+Subscription.h"

@implementation MKCollection (Subscription)

- (id)objectForKeyedSubscript:(NSString *)key
{
    return [self objectForKey:key];
}

- (void)setObject:(id)obj forKeyedSubscript:(NSString *)key
{
    [self setObject:obj forKeyedSubscript:key];
}

@end
