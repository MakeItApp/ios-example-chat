//
//  BDArenaPlayerData.h
//  arenaChatTester
//
//  Created by saver on 10/10/11.
//  Copyright 2011 ArenaDaemon Srl. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BDArenaPlayerData : NSObject {	
	@private
    NSInteger   auid;
    NSString*   accessToken;
	NSString*   nickname;
    NSString*   email;
    NSString*   gender;
    NSInteger   dateOfBirth;
    NSInteger   age;
    NSString*   avatarImageOriginalUrl;
    NSString*   avatarImageThumbUrl;
    BOOL        registered;
	NSString*   deviceModel;
	NSString*   deviceSystemName;
	NSString*   deviceSystemVersion;
}

@property (nonatomic, assign) NSInteger   auid;
@property (nonatomic, retain) NSString*   accessToken;
@property (nonatomic, retain) NSString*   nickname;
@property (nonatomic, retain) NSString*   email;
@property (nonatomic, retain) NSString*   gender;
@property (nonatomic, assign) NSInteger   dateOfBirth;
@property (nonatomic, assign) NSInteger   age;
@property (nonatomic, retain) NSString*   avatarImageOriginalUrl;
@property (nonatomic, retain) NSString*   avatarImageThumbUrl;
@property (nonatomic, assign) BOOL        registered;
@property (nonatomic, retain) NSString*   deviceModel;
@property (nonatomic, retain) NSString*   deviceSystemName;
@property (nonatomic, retain) NSString*   deviceSystemVersion;

- (id) initWithParams:(NSDictionary*)params;
- (id) initWithParams64:(NSDictionary*)params;
- (id) initWithPlayerData:(BDArenaPlayerData*)data;
- (NSString*) encodeProfileData;

@end
