//
//  MKCollection.h
//  mkApp
//
//  Created by FSS
//  Copyright (c) 2012 makeitapp.eu All rights reserved.
//
//

#import <Foundation/Foundation.h>

@class MKCollection;


/**
 A MKCollection represents an object stored in the collection with the given name.
 
 @warning *Important*: `$` and `.` characters cannot be used in object keys
 */
@interface MKCollection : NSObject

/** Getting Collection Info */

/**
 The name of the collection 
 */
@property (nonatomic, copy, readonly) NSString *collectionName;

/**
 The collection ID
 */
@property (nonatomic, strong) NSString *collectionId;

/**
 The date of last update
 */
@property (nonatomic, strong) NSDate *updatedAt;

/**
 The creation date
 */
@property (nonatomic, strong) NSDate *createdAt;

/**
 `YES` if the collection has not been saved, `NO` otherwise
 */
@property (nonatomic, readonly) BOOL isTransient;

/**
 `YES` if changes have been made to the collection since last save, `NO` otherwise
 */
@property (nonatomic, readonly) BOOL isChanged;

/**
  User that created this collection object.
 */
@property (nonatomic, readonly) id creatorId;

/** Creating and Initializing Collections */

/**
 Create collection with given name
 @param collectionName The collection name
 @return The initialized collection
 */
+ (MKCollection *)collectionWithName:(NSString *)collectionName;

/**
 Initialize a new collection
 @param collectionName The collection name
 @return The initialized collection
 */
- (id)initWithName:(NSString *)collectionName;

/**
 Returns allKeys of collection
 @return Array of keys (NSString)
 */
-(NSArray*)allKeys;

/**
 Returns a Dictionary of the all collection content
 @return Dictionary of  all values and keys
 */

-(NSDictionary*)allKeysAndValues;

/** Saving collections */


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

/** Refreshing collections */


/**
 Refreshes the collection
 
 Refreshes the collection with data stored on the server.
 @param error The error object to be set on error
 @return `YES` on success, `NO` on error
 */
- (BOOL)refresh:(NSError **)error;


/**
 Refreshes the collection in the background and invokes the callback on completion
 
 Refreshes the collection with data stored on the server.
 @param block The callback block
 */
- (void)refreshInBackgroundWithBlock:(void (^)(MKCollection *collection, NSError *error))block;

/** Deleting collections */


/**
 Deletes the collection
 @param error The error object to be set on error
 @return `YES` on success, `NO` on error
 */
- (BOOL)delete:(NSError **)error;


/**
 Deletes the collection in the background and invokes the callback block on completion
 @param block The callback block
 */
- (void)deleteInBackgroundWithBlock:(void (^)(MKCollection *collection, NSError *error))block;

/** Getting Objects*/

/**
 Gets the object stored at `key`.
 
 If the key does not exist in the saved object, tries to return a value from the unsaved changes.
 @param key The object key
 @return The object or `nil` if no object is set for `key`
 */
- (id)objectForKey:(NSString *)key;

/** Modifying Objects*/

/**
 Sets the object on a given `key`
 
 The object must be of type NSString, NSNumber, NSArray, NSDictionary, NSNull
 @param object The object to store
 @param key The object key
 @warning The key must not include an `$` or `.` character
 */
- (void)setObject:(id)object forKey:(NSString *)key;

/**
 Pushes (appends) the object to the list at `key`.
 
 Appends the object if a list exists at `key`, otherwise sets a single elemenet list containing `object` on `key`. If the `key` exists, but is not a list, the collection save will fail. Object must be a *JSON* type.
 @param object The object to push
 @param key The list key
 @warning The key must not include an `$` or `.` character
 */
- (void)pushObject:(id)object forKey:(NSString *)key;

/**
 Pushes (appends) all objects to the list at `key`
 
 Appends the objects if a list exists at `key`, otherwise sets `key` to the `objects` list. If the `key` exists, but is not a list, the collection save will fail. List may only contain *JSON* types.
 @param objects The object list
 @param key The list key
 @warning The key must not include an `$` or `.` character
 */
- (void)pushAllObjects:(NSArray *)objects forKey:(NSString *)key;

/**
 Removes all occurrences of object from the list at `key`
 
 If the `key` exists, but is not a list, collection save will fail.
 @param object The object to remove
 @param key The list key
 */
- (void)pullObject:(id)object forKey:(NSString *)key;

/**
 Removes all occurrences of objects from the list at `key`
 
 If the `key` exists, but is not a list, collection save will fail.
 @param objects The objects to remove
 @param key The list key
 */
- (void)pullAllObjects:(NSArray *)objects forKey:(NSString *)key;

/**
 Increments the number at `key` by `1`
 @param key The key to increment
 */
- (void)incrementKey:(NSString *)key;

/**
 Increments the number at `key` by `amount`
 @param key The key to increment 
 @param amount The increment amount. Can also be negative
 */
- (void)incrementKey:(NSString *)key byAmount:(NSNumber *)amount;

/**
 Resets the collection to it's last saved state
 */
- (void)reset;


+ (id)new UNAVAILABLE_ATTRIBUTE;
- (id)init UNAVAILABLE_ATTRIBUTE;
@end
