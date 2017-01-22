//
//  VioozerShare.h
//  VioozerAPI
//
//  Created by Zeev on 5/14/14.
//  Copyright (c) 2014 Quickode. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VioozerShare : NSObject
/**
 *  link 
 */
@property (strong, nonatomic) NSURL* shareURL;
@property (strong, nonatomic) NSString* text;

+(VioozerShare*) vioozerShareWithText:(NSString*)text
                             shareURL:(NSURL*)link;
@end
