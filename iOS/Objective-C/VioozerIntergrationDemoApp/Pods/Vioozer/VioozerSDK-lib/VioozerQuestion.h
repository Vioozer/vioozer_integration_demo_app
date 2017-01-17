//
//  VioozerQuestion.h
//  VioozerAPI
//
//  Created by Zeev on 5/1/14.
//  Copyright (c) 2014 Quickode. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@class VioozerLocation;

typedef enum QuestionRelevantTime
{
    QuestionRelevantTimeHour,
    QuestionRelevantTimeToday,
    QuestionRelevantTimeTomorrow,
    QuestionRelevantTimeNearFuture
}QuestionRelevantTime;


@interface VioozerQuestion : NSObject


@property (assign,nonatomic) MKMapType mapType;

@property (strong, nonatomic) NSString* questionId;

@property (strong, nonatomic) NSString * title;

@property (strong, nonatomic) NSString * subtitle;

@property (strong, nonatomic) NSString* text;

@property (strong, nonatomic) NSString* secondText;

@property (strong, nonatomic) VioozerLocation * location;

@property (strong, nonatomic) NSArray* arrAnswers;

@property (assign, nonatomic) QuestionRelevantTime relevantTimeInterval;

@property (assign, nonatomic) BOOL wantAddImage;

+(QuestionRelevantTime) convertRelevantFromString:(NSString*)string;


+(VioozerQuestion*) vioozerQuestionWithTitle:(NSString*)title
                                    subTitle:(NSString*)subtitle
                                        text:(NSString*)text
                                    location:(VioozerLocation*)location
                                relevantTime:(QuestionRelevantTime)relevantTime
                                wantAddImage:(BOOL)addImage;


+(VioozerQuestion*) vioozerQuestionWithQuestionID:(NSString*)questionId
                                            Title:(NSString*)title
                                         subTitle:(NSString*)subtitle
                                             text:(NSString*)text
                                         location:(VioozerLocation*)location
                                     relevantTime:(QuestionRelevantTime)relevantTime
                                     wantAddImage:(BOOL)addImage
                                       andAnswers:(NSArray*)arrAnswers;

-(NSString*)getRelevantTimeString;

@end
