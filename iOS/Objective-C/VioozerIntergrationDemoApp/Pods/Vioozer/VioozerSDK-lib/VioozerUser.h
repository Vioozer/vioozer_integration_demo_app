//
//  VioozerUser.h
//  VioozerAPI
//
//  Created by Zeev on 5/12/14.
//  Copyright (c) 2014 Quickode. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  represent the user of the sdk object
 */
@interface VioozerUser : NSObject

/**
 * userId from host application
 */
@property (strong, nonatomic) NSString* appUserID;
@property (strong, nonatomic) NSString* fullName;
@property (strong, nonatomic) NSString* firstName;
@property (strong, nonatomic) NSString* lastName;
@property (strong, nonatomic) NSString* email;

/**
 *  a dictionary that contains aditional values
 */
@property (strong, nonatomic) NSDictionary* dictAdditionalValues;


/**
 *  array of application userIDs strings
 */
@property (strong, nonatomic) NSArray* arrFollowing;


+(VioozerUser*) vioozerUserWithFirstName:(NSString*)firstName
                                lastName:(NSString*)lastName
                                fullName:(NSString*)fullName
                                   email:(NSString*)email
                               appUserID:(NSString*)userID
                            andFollowing:(NSArray*)following;


@end
