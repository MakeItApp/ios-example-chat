//
//  BDArenaAdClipConfigData.h
//  
//
//  Created by saver on 2/12/12.
//  Copyright 2012 ArenaDaemon Srl. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
//#import "BDArenaDataObjects.h"

typedef enum{
	BDArenaAdvAdClipCountdownLabelPositionTop		= 1,
	BDArenaAdvAdClipCountdownLabelPositionBottom	= 2
}BDArenaAdvAdClipCountdownLabelPosition;

@interface BDArenaAdClipConfigData : NSObject {
	@private
	
	NSString*								countdownText;
	BDArenaAdvAdClipCountdownLabelPosition	labelPosition;
	NSTextAlignment							textAlignment;
	NSString*								clickThruAlertTitle;
	NSString*								clickThruAlertMessage;
	NSString*								clickThruAlertCancelButtonTitle;
	NSString*								clickThruAlertOpenButtonTitle;
	NSString*								frequencyCapSlotIdentifier;
	BOOL									showLoadingView;
}

- (id) initWithConfigData:(BDArenaAdClipConfigData*)configData;

@property (nonatomic, retain) NSString*									countdownText;
@property (nonatomic, assign) BDArenaAdvAdClipCountdownLabelPosition	labelPosition;
@property (nonatomic, assign) NSTextAlignment							textAlignment;
@property (nonatomic, retain) NSString*									clickThruAlertTitle;
@property (nonatomic, retain) NSString*									clickThruAlertMessage;
@property (nonatomic, retain) NSString*									clickThruAlertCancelButtonTitle;
@property (nonatomic, retain) NSString*									clickThruAlertOpenButtonTitle;
@property (nonatomic, retain) NSString*									frequencyCapSlotIdentifier;
@property (nonatomic, assign) BOOL										showLoadingView;

@end
