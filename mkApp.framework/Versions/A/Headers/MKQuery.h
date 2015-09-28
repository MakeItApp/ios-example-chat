//
//  MKQuery.h
//  mkApp
//
//  Created by FSS
//  Copyright (c) 2012 makeitapp.eu All rights reserved.
//

#import "MKConstants.h"


@class MKCollection;

/**
 Class for performing queries on collection collections.
 */
@interface MKQuery : NSObject{
    BOOL service;
}

/** @name Options */

/**
 The collection name to perform the query on
 */
@property (nonatomic, copy, readonly) NSString *collectionName;

/**
 Limit number of returned results
 */
@property (nonatomic, assign) NSUInteger limit;

/**
 Override the default recursive limits in Baas
 */
@property (nonatomic, assign) NSUInteger limitRecursion;

/**
 Number of results to skip. Will be ignored if map reduce is set.
 */
@property (nonatomic, assign) NSUInteger skip;

/**
 The cache policy to use for the query.
 */
@property (nonatomic, assign) MKAPPCachePolicy cachePolicy;

/** @name Creating and Initializing Queries */

/**
 Creates a new query for the given collection name
 @param collectionName The name of the collection to query
 @return The initialized query
 */
+ (MKQuery *)queryWithcollectionName:(NSString *)collectionName;

/**
 Initializes a new query for the given collection name
 @param collectionName The name of the collection to fetch.
 @return The initialized query
 */
- (id)initWithcollectionName:(NSString *)collectionName;

/** @name Ordering */

/**
 Sorts the query in ascending order by key
 
 This key will be ignored when a map reduce is performed.
 @param key The sort key
 */
- (void)orderAscendingByKey:(NSString *)key;

/**
 Sorts the query in descending order by key
 
 This key will be ignored when a map reduce is performed.
 @param key The sort key
 */
- (void)orderDescendingByKey:(NSString *)key;

/**
 Sorts the query in ascending order by creation date
 */
- (void)orderAscendingByCreationDate;

/**
 Sorts the query in desscending order by creation date
 */
- (void)orderDescendingByCreationDate;

/**
 Sorts the query in ascending order by update date
 */
- (void)orderAscendingByUpdateDate;

/**
 Sorts the query in desscending order by update date
 */
- (void)orderDescendingByUpdateDate;

/** @name Logical Operators */

/**
 Add an **OR** condition to the query using the proxy object

    [[query or] whereKey:@"key" equalTo:@"value"];
    [[query or] whereKey:@"key2" equalTo:@"value2"];
 
 Conditions performed on the **OR** proxy will be concatenated with **OR**.
 
 @return or The OR proxy object.
 */
- (MKQuery *)or;

/**
 Add an **AND** condition using the proxy object
 
    [[query and] whereKey:@"key" equalTo:@"value"];
    [[query and] whereKey:@"key2" equalTo:@"value2"];
 
 Conditions performed on the **AND** proxy will be concatenated with **AND**.
 (NOT WORK, NOT DOCUMENTED IN Baas 0.6.9v, MAY WORK IN FUTURE VERSIONS) 
 @return and The AND proxy object.
 */
//- (MKQuery *)and;

/** @name Conditions */

/**
 Adds an equal condition to the query
 @param key The collection key
 @param object The condition object
 */
- (void)whereKey:(NSString *)key equalTo:(id)object;

/**
 Adds a less-than condition to the query
 @param key The collection key
 @param object The condition object
 */
- (void)whereKey:(NSString *)key lessThan:(id)object;

/**
 Adds a less-than-or-equal condition to the query
 @param key The collection key
 @param object The condition object
 */
- (void)whereKey:(NSString *)key lessThanOrEqualTo:(id)object;

/*!
 Adds a greater-than condition to the query
 @param key The collection key
 @param object The condition object
 */
- (void)whereKey:(NSString *)key greaterThan:(id)object;

/**
 Adds a greater-than-or-equal condition to the query
 @param key The collection key
 @param object The condition object
 */
- (void)whereKey:(NSString *)key greaterThanOrEqualTo:(id)object;

/**
 Adds an not-equal condition to the query
 @param key The collection key
 @param object The condition object
 */
- (void)whereKey:(NSString *)key notEqualTo:(id)object;

/**
 Adds an contained-in condition to the query
 
 The key value must be contained in the given array. The value for `key` can also be an array.
 @param key The collection key
 @param array The objects to check
 */
- (void)whereKey:(NSString *)key containedIn:(NSArray *)array;

/**
 Adds an not-contained-in condition to the query
 
 The key value must not be contained in the given array. The value for `key` can also be an array.
 @param key The collection key
 @param array The objects to check
 */
- (void)whereKey:(NSString *)key notContainedIn:(NSArray *)array;

/**
 Adds an contains-all condition to the query
 
 The key value must contain all values in the given array. The value for `key` can also be an array.
 @param key The collection key
 @param array The objects to check
 */
- (void)whereKey:(NSString *)key containsAllIn:(NSArray *)array;

/**
 Matches the regex with no options set
 @param key The collection key
 @param regex The regex to match
 @see <whereKey:matchesRegex:options:>
 */
- (void)whereKey:(NSString *)key matchesRegex:(NSString *)regex;

/**
 Matches the regex using the provided option mask
 @param key The collection key
 @param regex The regex to match
 @param options The regex options
 */
- (void)whereKey:(NSString *)key matchesRegex:(NSString *)regex options:(MKAPPRegexOption)options;

/**
 Checks if the object for key contains the string
 
 Does not work on array fields
 @param key The collection key
 @param string The string to match
 @param caseInsensitive `YES` if the string is case insensitive, `NO` otherwise
 */
- (void)whereKey:(NSString *)key containsString:(NSString *)string caseInsensitive:(BOOL)caseInsensitive;

/**
 Checks if the object for key has the given prefix
 @param key The collection key
 @param prefix The prefix string to match
 */
- (void)whereKey:(NSString *)key hasPrefix:(NSString *)prefix;

/**
 Checks if the object for key has the given suffix
 @param key The collection key
 @param suffix The suffix string to match
 */
- (void)whereKey:(NSString *)key hasSuffix:(NSString *)suffix;

/**
 Checks if the collection key exists
 (IT WORK, NOT DOCUMENTED IN Baas 0.6.9v, MAY NOT WORK IN FUTURE VERSIONS)
 @param key The collection key
 */
//- (void)whereKeyExists:(NSString *)key;

/**
 Checks if the collection key does not exist
 (IT WORK, NOT DOCUMENTED IN Baas 0.6.9v, MAY NOT WORK IN FUTURE VERSIONS)
 @param key The collection key
 */
//- (void)whereKeyDoesNotExist:(NSString *)key;

/**
 Checks if the collection ID key matches 
 @param collectionId The collection ID to match
 */
- (void)wherecollectionIdMatches:(NSString *)collectionId;

/**
 Checks objects with key point values near the point given and within the maximum distance given in radians
 Require a "2d" spatial index created on the key
 (IT WORK, NOT DOCUMENTED IN Baas 0.6.9v, MAY NOT WORK IN FUTURE VERSIONS) 
 @param sequenceNum The sequence number to match
 */
//-(void)whereKey:(NSString *)key nearPoint:(NSArray*)point withinDistance:(NSNumber*)distance;

/** @name collection Key Subsets */

/**
 Excludes the specified keys from the result entities
 
 This method is mutually exclusive to <includeKeys:>
 @param keys The keys to exclude
 */
- (void)excludeKeys:(NSArray *)keys;

/**
 Includes only the specified keys in the result entities

 This method is mutually exclusive to <excludeKeys:>
 @param keys The keys to include
 */
- (void)includeKeys:(NSArray *)keys;

/** @name Executing Queries */

/**
 Finds all matching entities
 @return The matching entities
 */
- (NSArray *)findAll;

/**
 Finds all matching entities
 @param error The error object to set on error
 @return The matching entities
 */
- (NSArray *)findAll:(NSError **)error;

/**
 Finds all matching entities in the background and returns them to the callback block
 @param block The result callback
 */
- (void)findAllInBackgroundWithBlock:(void (^)(NSArray *results, NSError *error))block;

/** @name Aggregation */

/**
 Counts the entities matching the query
 (NOT WORK, NOT DOCUMENTED IN Baas 0.6.9v, MAY WORK IN FUTURE VERSIONS)
 @return The matched collection count
 */
- (NSInteger)countAll;

/**
 Counts the entities matching the query
 (NOT WORK, NOT DOCUMENTED IN Baas 0.6.9v, MAY WORK IN FUTURE VERSIONS)
 @param error The error object that is written on error
 @return The matched collection count
 */
- (NSInteger)countAll:(NSError **)error;

/**
 Counts the entities matching the query in the background and returns the result to the block
 (NOT WORK, NOT DOCUMENTED IN Baas 0.6.9v, MAY WORK IN FUTURE VERSIONS)
 @param block The result callback block
 */
- (void)countAllInBackgroundWithBlock:(void (^)(NSUInteger count, NSError *error))block;

/** @name Resetting Conditions */

/**
 Resets all query conditions
 */
- (void)reset;

+ (id)new UNAVAILABLE_ATTRIBUTE;
- (id)init UNAVAILABLE_ATTRIBUTE;

@end
