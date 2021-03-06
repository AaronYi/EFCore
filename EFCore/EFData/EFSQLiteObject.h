//
// Created by yizhuolin on 12-10-19.
//
// To change the template use AppCode | Preferences | File Templates.
//


#import <Foundation/Foundation.h>
@import FMDB;

#define FieldName(property) [[@(#property) componentsSeparatedByString: @"."] lastObject]

@protocol EFSQLiteObject

- (void)startModification;

- (void)endModification;

+ (NSSet *)excludedFields;

+ (NSArray *)fieldsForPersistence;

+ (NSArray *)primaryKey;

+ (NSString *)tableName;

@end

@interface EFSQLiteObject : NSObject <EFSQLiteObject>

@property(nonatomic, readonly) NSArray *changedFields;

- (id)initWithFMResultSet:(FMResultSet *)resultSet;
- (id)initWithFMResultSet:(FMResultSet *)resultSet ignoreFieldNotExist:(BOOL) ignore;

- (void)startModification;

- (void)endModification;

+ (NSSet *)excludedFields;

+ (NSArray *)fieldsForPersistence;

+ (NSArray *)primaryKey;

+ (NSString *)tableName;
@end