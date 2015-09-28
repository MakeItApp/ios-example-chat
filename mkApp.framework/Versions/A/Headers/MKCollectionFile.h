//
//  MKCollectionFile.h
//  mkApp
//
//  Created by FSS on 16/02/14.
//  Copyright (c) 2014 MakeItApp.eu. All rights reserved.
//

#import <mkApp/mkApp.h>

@interface MKCollectionFile : MKCollection{
    BOOL service;
}

/**
 The file name
 */
@property (nonatomic, copy) NSString *name;


/**
 The file data
 */
@property (nonatomic, strong, getter = loadData) NSData *data;


/** @name Creation of a new instance */


+(MKCollectionFile* )file;

/**
 Creates a new file with the given name and data
 @param name The filename
 @param data The file data
 @return The initialized file
 */
+ (MKCollectionFile *)fileWithName:(NSString *)name data:(NSData *)data;

/** @name Loading Data */

/**
 Loads data for the specified filename
 @return The file data
 @exception NSInternalInconsistencyException Raised if name is not set
 */
- (NSData *)loadData;

/**
 Loads data for the specified filename
 @param error The error object set on error
 @return The file data
 @exception NSInternalInconsistencyException Raised if name is not set
 */
- (NSData *)loadData:(NSError **)error;

/**
 Loads data for the specified filename in the background
 @param block The result callback block
 @exception NSInternalInconsistencyException Raised if name is not set
 */
- (void)loadDataInBackgroundWithBlock:(void (^)(BOOL success, NSData *data, NSError *error))block;

#pragma mark - save
/** @name Saving Files */

/**
 Saves the collection
 @param error The error object to be set on error
 @return `YES` on success, `NO` on error
 @exception NSInvalidArgumentException Raised if any key contains an `$` or `.` character.
 */
- (BOOL)save:(NSError **)error;

/**
 Saves the collection in the background and invokes callback on completion
 @param block The save callback block
 @exception NSInvalidArgumentException Raised if any key contains an `$` or `.` character.
 */
- (void)saveInBackgroundWithBlock:(void (^)(MKCollection *collection, NSError *error))block;


@end
