//
//  VioozerFeedItem.h
//  MTFan
//
//  Created by Yedidya Reiss on 8/18/14.
//  Copyright (c) 2014 Grupo Expansión. All rights reserved.
//

#import <Foundation/Foundation.h>

@class VioozerQuestion;


/**
 *  this class represent feed item that received from the Vioozer SDK
 */
@interface VioozerFeedItem : NSObject
{
	VioozerQuestion* _question;
	BOOL _isMyQuestion;
	BOOL _canWriteAnswer;
	int _saidThanksType;
	NSString* _questionId;
	NSString* _type;
	
}

/** time stamp of the feed item */
@property (assign, nonatomic) NSTimeInterval timeStamp;

/** latitude of the feed item */
@property (assign,nonatomic) double latitude;

/** longitude of the feed item */
@property (assign,nonatomic) double longitude;

/** true iff the feed item location can be a trigger for another question */
@property (assign,nonatomic) BOOL vioozable;

/** url of the image of the feed */
@property (strong, nonatomic) NSURL* imageUrl;

/** url of the logo of the feed item */
@property (strong, nonatomic) NSURL* logoUrl;

/** the app user id that is assosiated with the feed item (may be nill) */
@property (strong, nonatomic) NSString* appUserId;

/** subtitle of the feed */
@property (strong, nonatomic) NSString* subtitle;

/** the text of the feed */
@property (strong, nonatomic) NSString* text;

/** the title of the feed */
@property (strong, nonatomic) NSString* title;

/** the data id that is represented by the feed */
@property (strong, nonatomic) NSString* feedItemId;

/** true iff this feed item was shared */
@property (assign,nonatomic) BOOL shared;

/** true iff this feed item is user item feed */
@property (assign,nonatomic) BOOL isMine;

/** true iff this is question that the user asked */
@property (assign,nonatomic, readonly) BOOL isMyQuestion;

/** true iff the feed item is still relevant to the user */
@property (assign,nonatomic) BOOL isRelevant;

/** true iff the user didn't read the feed item yet */
@property (assign,nonatomic) BOOL unread;

/** true iff the feed represent an answer */
@property (assign,nonatomic) BOOL hasAnswer;

/** true iff the feed represent an answer and it is the user answer*/
@property (assign,nonatomic) BOOL isMyAnswer;

/** share text for this feed item */
@property (strong, nonatomic) NSString* shareText;

/** share url for this feed item */
@property (strong, nonatomic) NSString* shareURL;


@end
