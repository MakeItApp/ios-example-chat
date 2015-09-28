/*
 *  BDArenaPlayConnectorDelegate.h
 *  NCC2
 *
 *  Created by saver on 2/17/12.
 *  Copyright 2012 ArenaDaemon Srl. All rights reserved.
 *
 */

#import <Foundation/Foundation.h>
#import "BDArenaPlayConnector.h"

#pragma mark -
#pragma mark BDArenaPlayConnectorDelegate

@protocol BDArenaPlayConnectorDelegate <NSObject>

@optional

- (void) arenaPlay:(BDArenaPlayConnector*)connector requestDidFail:(NSError*)error;

- (void) arenaPlayConnectionDidClose;
- (void) arenaPlayConnectionEstabilished;
- (void) arenaPlayConnectionFailedWithError:(NSError*)error;
- (void) arenaPlayLocalPlayerDidLoginFromDifferentDevice;

//- (void) arenaPlay:(BDArenaPlayConnector*)connector didRemoveTableWithData:(BDArenaTableData*)tableData;
- (void) arenaPlay:(BDArenaPlayConnector*)connector didRemoveTableWithId:(NSString*)tableId;

- (void) arenaPlay:(BDArenaPlayConnector*)connector tablesListReceived:(BDArenaTablesArray*)tables activeMatches:(NSInteger)activeMatches activePlayers:(NSInteger)activePlayers;
- (void) arenaPlay:(BDArenaPlayConnector*)connector paramReceived:(NSString*)param forTableId:(NSString*)tableId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector registrationSuccessfullyCompletedToTable:(NSString*)tableId withMatchId:(NSInteger)matchId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector alreadyRegisteredToTableWithId:(NSString*)tableId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector unregistrationSuccessfullyCompletedFromTableWithId:(NSString*)tableId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector unregistrationFailedFromTableWithId:(NSString*)tableId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector notRegisteredToTableWithId:(NSString*)tableId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector playersListReceived:(BDArenaPlayersArray*)players forTableId:(NSString*)tableId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector status:(ARENA_PLAYER_STATUS)status receivedForPlayerWithAuid:(NSInteger)auid;
- (void) arenaPlay:(BDArenaPlayConnector*)connector messageSuccessfullySent:(NSString*)message inMatchWithId:(NSInteger)matchId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector newMessageReceived:(NSString*)message fromPlayer:(BDArenaPlayerData*)playerData inMatchWithId:(NSInteger)matchId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector matchDidStart:(BDArenaMatchData*)matchData;
- (void) arenaPlay:(BDArenaPlayConnector*)connector messageSuccessfullySent:(NSString*)message toPlayerWithAuid:(NSInteger)auid inMatchWithId:(NSInteger)matchId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector matchSuccessfullyLeft:(NSInteger)matchId;

- (void) arenaPlay:(BDArenaPlayConnector*)connector leaveMatchWithId:(NSInteger)matchId didFailWithError:(NSError*)error;

- (void) arenaPlay:(BDArenaPlayConnector*)connector playerWithAuid:(NSInteger)auid leftMatchWithId:(NSInteger)matchId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector playersListReceived:(BDArenaPlayersArray*)players forMatchId:(NSInteger)matchId;

- (void) arenaPlay:(BDArenaPlayConnector*)connector challengeCreationFailedWithError:(NSError*)error;
- (void) arenaPlay:(BDArenaPlayConnector*)connector challengeCreationSuccessfullyCompletedWithChallengeId:(NSString*)challengeId withChallengeName:(NSString*)name withParam:(NSString*)param withPlayers:(BDArenaPlayersArray*)players withMatchId:(NSInteger)matchId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector challengeCancellationForId:(NSString*)challengeId failedWithError:(NSError*)error;
- (void) arenaPlay:(BDArenaPlayConnector*)connector challengeCancellationSuccessfullyCompletedForChallengeWithId:(NSString*)challengeId;

- (void) arenaPlay:(BDArenaPlayConnector*)connector challengeWithId:(NSString*)challengeId cancelledWithReason:(ARENA_CHALLENGE_CANCELLATION_REASON)reason;
- (void) arenaPlay:(BDArenaPlayConnector*)connector challengeInvitationReceivedFromPlayer:(BDArenaPlayerData*)organizer withChallengeId:(NSString*)challengeId withChallengeName:(NSString*)name withParam:(NSString*)param withPlayers:(BDArenaPlayersArray*)players withMatchId:(NSInteger)matchId;

- (void) arenaPlay:(BDArenaPlayConnector*)connector playerWithAuid:(NSInteger)auid leftChallengeWithId:(NSString*)challengeId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector invitationToChallengeWithId:(NSString*)challengeId refusedByPlayerWithAuid:(NSInteger)auid;
- (void) arenaPlay:(BDArenaPlayConnector*)connector invitationToChallengeWithId:(NSString*)challengeId acceptedByPlayerWithAuid:(NSInteger)auid;

- (void) arenaPlay:(BDArenaPlayConnector*)connector invitationSuccessfullyRefusedToChallengeWithId:(NSString*)challengeId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector invitationRefusalToChallengeWithId:(NSString*)challengeId didFailWithError:(NSError*)error;

- (void) arenaPlay:(BDArenaPlayConnector*)connector invitationSuccessfullyAcceptedToChallengeWithId:(NSString*)challengeId;
- (void) arenaPlay:(BDArenaPlayConnector*)connector invitationAcceptanceToChallengeWithId:(NSString*)challengeId didFailWithError:(NSError*)error;

- (void) arenaPlay:(BDArenaPlayConnector*)connector leaveChallengeWithId:(NSString*)challengeId didFailWithError:(NSError*)error;
- (void) arenaPlay:(BDArenaPlayConnector*)connector challengeSuccessfullyLeftForChallengeWithId:(NSString*)challengeId;

- (void) arenaPlay:(BDArenaPlayConnector*)connector readyToStartChallengeWithId:(NSString*)challengeId
          withName:(NSString*)challengeName
       withMatchId:(NSInteger)matchId
         withParam:(NSString*)param
       withPlayers:(BDArenaPlayersArray*)players
      andOrganizer:(BDArenaPlayerData*)organizer;

- (void) arenaPlay:(BDArenaPlayConnector*)connector startChallengeWithId:(NSString*)challengeId didFailWithError:(NSError*)error;

@end
