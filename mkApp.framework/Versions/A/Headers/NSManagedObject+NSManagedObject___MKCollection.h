//
//  NSManagedObject+NSManagedObject___MKCollection.h
//  mkApp
//
//  Created by Mia Srl on 4/30/13.
//  Copyright (c) 2013 MakeItApp.eu. All rights reserved.
//

#import <CoreData/CoreData.h>

@class MKCollection;

@interface NSManagedObject (NSManagedObject___MKCollection)

/** @name NSManagedObject MKCollection category methods */


/*!
 Create a MKCollection from current NSManagedObject.
 @result Returns a new MKCollection object.
*/
-(MKCollection*)getMKCollection;


/*!
 Create NSManagedObject from a MKCollection performing an insert or Update in the database.
 @param obj The MKCollection object.
 @param moContext the database to sync.
 @param field the NSManagedObject key that has to be use to lookup existing NSManagedObject in database.
 @result Returns a new inserted/updated NSManagedObject.
 */
 +(NSManagedObject*)objectFromMKCollection:(MKCollection*)obj intoMoContext:(NSManagedObjectContext*)moContext usingField:(NSString*)field __deprecated;


/*!
 Create NSManagedObject from a MKCollection performing an insert or Update in the database.
 @param obj The MKCollection object.
 @param moContext the database to sync.
 @param field the NSManagedObject key that has to be use to lookup existing NSManagedObject in database.
 @param error not nil if an error occured
 @result Returns a new inserted/updated NSManagedObject.
 */
+(NSManagedObject*)objectFromMKCollection:(MKCollection*)obj intoMoContext:(NSManagedObjectContext*)moContext usingField:(NSString*)field error:(NSError**)error;

/*!
 Query database for NSManagedObject starting from a MKCollection
 @param entity the entity to look after.
 @param afield a key to use in the NSPredicate.
 @param moContext the database to sync.
 @param obj the MKCollection to use in the NSPredicate
 @result Returns an Array of NSManagedObjects.
 */
+(NSArray*)queryEntity:(NSEntityDescription*) entity byField:(NSString*)afield intoMoContext:(NSManagedObjectContext*)moContext forMKCollection:(MKCollection*)obj;


@end
