//
//  BDArenaTableData.h
//  NCC2
//
//  Created by saver on 2/12/12.
//  Copyright 2012 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BDArenaTableData : NSObject {
	@private
	
	NSString*	tableId;
	NSString*	referenceName;
	NSString*	symbolicName;
	NSInteger	maxPlayers;
	NSInteger	registeredPlayers;
	BOOL		alreadyRegistered;
	NSString*	param;
}

@property (nonatomic, readonly, retain) NSString*	tableId;
@property (nonatomic, readonly, retain) NSString*	symbolicName;
@property (nonatomic, readonly, retain) NSString*	referenceName;
@property (nonatomic, readonly, assign) NSInteger	maxPlayers;
@property (nonatomic, readonly, assign) NSInteger	registeredPlayers;
@property (nonatomic, readonly, assign) BOOL		alreadyRegistered;
@property (nonatomic, readonly, retain) NSString*	param;

- (id) initWithParams:(NSDictionary*)params;

@end
