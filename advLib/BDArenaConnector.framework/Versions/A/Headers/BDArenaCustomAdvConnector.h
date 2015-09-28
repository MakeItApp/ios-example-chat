//
//  BDArenaCustomAdvConnector.h
//  meteo_bdtester
//
//  Created by saver on 01/04/14.
//  Copyright (c) 2014 Arena Daemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BDArenaDataObjects.h"
#import "BDArenaAdvConnectorDelegate.h"
#import "BDArenaAdvConnector.h"

@interface BDArenaCustomWebView : UIWebView
@end

@interface BDArenaCustomAdvConnector : BDArenaAdvConnector

- (void) requestCustomBannerWithParams:(NSDictionary*)params;
- (void) disconnectFromAdv:(NSInteger)sock;
- (NSInteger) connectToAdv:(NSDictionary*)params;

@end
