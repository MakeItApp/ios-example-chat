//
//  BDArenaRoomData.h
//  arenaChatTester
//
//  Created by saver on 10/10/11.
//  Copyright 2011 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface BDArenaRoomData : NSObject {
	NSString* name;
	NSInteger numberOfPlayers;
	NSString* param;
}

@property (nonatomic, retain, readonly) NSString* name;
@property (nonatomic, assign, readonly) NSInteger numberOfPlayers;
@property (nonatomic, retain, readonly) NSString* param;

- (id) initWithParams:(NSDictionary*)params;

@end
