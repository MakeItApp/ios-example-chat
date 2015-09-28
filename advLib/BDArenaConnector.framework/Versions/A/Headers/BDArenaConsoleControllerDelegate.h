//
//  BDArenaConsoleControllerDelegate.h
//  BDArenaConnectorClient
//
//  Created by Salvatore Iodice on 2/24/12.
//  Copyright (c) 2012 ArenaDaemon Srl. All rights reserved.
//

#ifndef BDArenaConnectorClient_BDArenaConsoleControllerDelegate_h
#define BDArenaConnectorClient_BDArenaConsoleControllerDelegate_h

@class BDArenaConsoleController;

@protocol BDArenaConsoleControllerDelegate <NSObject>

@optional

-(void) arenaConsoleControllerCloseButtonClicked:(BDArenaConsoleController*)controller;

@end

#endif
