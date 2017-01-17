//
//  VioozerAPI.h
//  VioozerAPI
//
//  Created by Zeev on 4/27/14.
//  Copyright (c) 2014 Quickode. All rights reserved.
//



#import <Foundation/Foundation.h>
#import "VioozerLocation.h"
#import "VioozerUser.h"
#import "VioozerShare.h"
#import "VioozerQuestion.h"
#import "VioozerFeedItem.h"


typedef enum VioozerLanguage
{
	VioozerLanguageEnglish,
	VioozerLanguageSpanish,
}VioozerLanguage;



@import CoreLocation;


/**
 *  protocol for send data to your application in some cases
 */
@protocol VioozerAPIDelegate <NSObject>


@optional
/**
 *  delegate for share data - application need to share it via social networks
 *
 *  @param share object with share details
 */
-(void) vioozerWantsToShare:(VioozerShare*)share;

/**
 *  will determine the background image of the UINavigationBar in Vioozer UIViewContorllers
 *
 *  @return the image name for the UINavigationBar image.
 */
-(NSString*) vioozerNeedNavigationLogoImage;

/**
 * delegate for update the badge icon
 *
 * @param unread count.
 */
-(void)vioozerDidChangeUnreadCount:(NSInteger)unreadCount;


@end

/** short call for the VioozerApi singltone */
#define VIOOZER_API [VioozerAPI sharedInstance]


/**
 *  Vioozer SDK singltone for call all Vioozer functionallity
 *  call all class function just via VIOOZER_API define or [VioozerAPI sharedInstance] method

 ##  instructions for embed VIoozerSDK:


 1. drag and drop all 'VioozerSDK-lib' directory to your Project
 2. add those frameworks to your project:
 CoreData.framework
 SystemConfiguration.framework
 libz.dylib
 libsqlite3.dylib
 CoreMedia.framework
 QuartzCore.framework
 AVFoundation.framework
 ImageIO.framework

 3. add to your 'Build Settings' the flag '-ObjC' to the key - 'Other Linker Flags'

 4. add #import "VioozerSDK.h" to your .pch file
 5. mark appDelegate as implement VioozerAPIDelegate protocol
 6. add to application:didFinishLaunchingWithOptions:

 a. init the SDK - example: when Appdelegate will be the Vioozer delegate add this line:

 [VIOOZER_API initializeVioozerApiWithKey:APP_KEY delegate:self WithLaunchOptions:launchOptions];

 b. register for remote notification - with 'UIRemoteNotificationTypeNewsstandContentAvailability' type

 if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)])
 {
 UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:(UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert) categories:nil];
 [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
 }
 else
 {
 UIRemoteNotificationType types = UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeAlert | UIRemoteNotificationTypeSound;
 [[UIApplication sharedApplication] registerForRemoteNotificationTypes:types];
 }


 7. implement in your delegate class all VioozerAPIDelegate function
 8. add to application:didRegisterForRemoteNotificationsWithDeviceToken:

 [VIOOZER_API remoteNotificationDidRegisterDeviceToken:deviceToken];

 9. add to application:didReceiveRemoteNotification:fetchCompletionHandler:

 if ([[userInfo objectForKey:@"VIOOZER"] isEqualToString:@"VIOOZER"])
 {
 [VIOOZER_API receivedRemoteNotification:userInfo withApplicationState:application.applicationState andCompletionHandler:completionHandler];
 }
 else
 {
 // enter your push code here
 completionHandler(UIBackgroundFetchResultNewData);
 }

 10. add background modes for target:
 in your project target, capabilities tab, background modes - select 'Background fetch', 'Remote notification' and 'Location updates'

 11. call to checkInWithVioozerLocation: when user checked-in in new location
 12. call to updateLocation: in each time your app know about new location from GPS
 13. call to updateUser: when your application know about any change in user details
 */

@interface VioozerAPI : NSObject

/** vioozer api delegate */
@property (weak, nonatomic) id<VioozerAPIDelegate> delegate;

/**
 *  singltone method
 *
 *  @return the singletone VioozerAPI instance
 */
+(VioozerAPI*) sharedInstance;

/**
 *  initialize all Vioozer SDK
 *  must to call this function in application:didFinishLaunchingWithOptions:
 *
 *  @param apiKey key for identifier the application
 *  @param delegate the object that implement VioozerAPIDelegate protocol to catch all SDK delegate
 *  @param launchOptions application launchOptions
 */
-(void) initializeVioozerApiWithKey:(NSString*)apiKey delegate:(id<VioozerAPIDelegate>)delegate WithLaunchOptions:(NSDictionary *)launchOptions withLanguage:(VioozerLanguage)language;

/**
 *  update the SDK about new remote notification token
 *
 *  @param deviceToken NSData received from 'application:didRegisterForRemoteNotificationsWithDeviceToken:'
 */
-(void) remoteNotificationDidRegisterDeviceToken:(NSData*)deviceToken;


/**
 function for pass the remote notification from appliction to SDK.

 send dictionary push data when received Vioozer push
 need to call this function when application received remote notification - look class documentation

 @param data push notification data
 @param state application state for show internal notification needed
 @param completionHandler handler for complete fetch result
 */
-(void)receivedRemoteNotification:(NSDictionary*)data withApplicationState:(UIApplicationState)state andCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/**
 function for pass the remote notification from appliction to SDK.

 send dictionary push data when received Vioozer push
 need to call this function when application received remote notification - look class documentation

 @param data push notification data
 @param state application state for show internal notification needed
 */
-(void)receivedRemoteNotification:(NSDictionary*)data withApplicationState:(UIApplicationState)state;


/**
 function for notifying the SDK about significant loaction change.
*/
- (void)reportSignificantLocationChange;

/**
 function for notifying the SDK about significant loaction change.
 
@param completionHandler handler for complete fetch result
*/
- (void)reportBackgroundFetchWithCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

/**
 *  show ask question view controller with VioozerLocation object
 *
 *  @param arrVioozerLocations   array of VioozerLocation objects
 *
 */
-(void) showAskQuestionOnLocations:(NSArray*)arrVioozerLocations inCategories:(NSArray*)arrCategories;



/**
 *  show ask question view controller with array
 * of VioozerLocation objects in Map/ List mode
 *
 *  @param arrVioozerLocations   array of VioozerLocation objects
 *  @param arrCategories   array of categories
 *  @param isListMode   true if the list should open automatically when entering the screen, false if not
 *
 */
-(void) showAskQuestionOnLocations:(NSArray*)arrVioozerLocations inCategories:(NSArray*)arrCategories inListMode:(BOOL)isListMode;



/**
 *  get the count of unread feed items.
 *
 *@param block	will return the count of unread feed items or negative number if error accured
 */
-(void) getUnreadCounterWithCompletionBlock:(void (^) (NSInteger unreadCount)) block ;


/**
 * presents my activity view controller
 */
-(void)openMyActivity;

/**
 * @return my activity view controller
 */
-(UIViewController *)getMyActivityViewController;

/**
 * tells the server to disable/enable push sending to this user.
 */
-(void)enablePushNotifications:(BOOL)enable;


/**
 * tells the server that the user chooses to share / not to share his/her location
 */
-(void)enableLocationServices:(BOOL)enable;



-(void)openThanks;


/**
 *  set the SDK language
 *	@note if no language was set the SDK will
 * take the device language if supported, and if not it will English localization
*/
-(void)setSDKLanguage:(VioozerLanguage)language;


/////////////////////////////////////////////////
/////////////////////////////////////////////////

////////////////   NOT FOR USE //////////////////

/////////////////////////////////////////////////
/////////////////////////////////////////////////

/**
 *  UI component the ask came from
 */
typedef enum AskQuestionSourceUI
{
    AskQuestionSourceUIFeed,
    AskQuestionSourceUIMatch,
    AskQuestionSourceUIMenu
}AskQuestionSourceUI;

/**
 *  the enviroment of the SDK
 */
typedef enum VioozerSDKEnvironment {
	VioozerSDKEnvironmentUndefined,
	VioozerSDKEnvironmentDev,
	VioozerSDKEnvironmentAdhoc,
	VioozerSDKEnvironmentProd
} VioozerSDKEnvironment;




/** this notification will be thrown whenever the vioozer sdk has the initials value that are needed to run */
#define VIOOZER_IS_READY_NOTIFICATION @"VIOOZER_IS_READY_NOTIFICATION"

/** this notification will be thrown if the vioozer sdk failed to initial its values */
#define VIOOZER_FAILED_NOTIFICATION @"VIOOZER_FAILED_NOTIFICATION"

/** this notification will be thrown if the vioozer sdk failed to download the image folder*/
#define VIOOZER_FAILED_NOTIFICATION_DOWNLOAD @"VIOOZER_FAILED_NOTIFICATION_DOWNLOAD"

/** this notification will be thrown if the vioozer sdk failed due to timeout*/
#define VIOOZER_FAILED_NOTIFICATION_TIMEOUT @"VIOOZER_FAILED_NOTIFICATION_TIMEOUT"


/** this notification will be thrown when the value of the unread count in my activity has changed
 * in the user info it returns NSNunber - the current number of unread counts
 */
#define VIOOZER_UNREAD_COUNT_IN_MY_ACTIVITY_HAS_CHANGED @"VIOOZER_UNREAD_COUNT_IN_MY_ACTIVITY_HAS_CHANGED"

/** this notification will be thrown when the group screen is toggled down*/
#define VIOOZER_GROP_SCREEN_TOGGLED_DOWN @"VIOOZER_GROP_SCREEN_TOGGLED_DOWN"


/**
 *  toggle up the groups view
 *
 *  @param vc - should be a searchLocation view controller
 */
-(void)toogleGroupUp:(UIViewController *)vc;


/**
 *  update Vioozer for new location that user checked-in
 *
 *  @param location    VioozerLocation object for checkin details
 *  @param text        Text the user wrote while he checked-in
 *  @param arrCheckins array of VioozerLocation object with nerby chekins
 */
-(void) checkInWithVioozerLocation:(VioozerLocation*)location checkinText:(NSString*)text andNerbyCheckins:(NSArray*)arrCheckins;

/**
 *  get vioozer feed - need to save the questions object for send it when user pressed on it
 *
 *  @param fromTime     get feeds not earlier than this date
 *  @param maxEvents    maximum number of events to receive
 *  @param arrFollowing array of strings for user's following - in order to send relevant feed
 *  @param completion   block with resuls - array of VioozerFeedItem objects
 *  @param failedBlock  failed block
 */
-(void) getFeedFromTime:(NSDate*)fromTime maxEvents:(NSInteger)maxEvents ForFollowing:(NSArray*)arrFollowing withCompletionBlock:(void (^)(NSArray* arrQuestions))completion andFailedBlock:(void (^)())failedBlock;

/**
 *  get vioozer feed - need to save the questions object for send it when user pressed on it
 *
 *  @param fromTime     get feeds not earlier than this date
 *  @param maxEvents    maximum number of events to receive
 *  @param completion   block with resuls - array of VioozerFeedItem objects
 *  @param failedBlock  failed block
 */
-(void) getMyFeedFromTime:(NSDate*)fromTime maxEvents:(NSInteger)maxEvents withCompletionBlock:(void (^)(NSArray* arrQuestions))completion andFailedBlock:(void (^)())failedBlock;

/**
 *  get vioozer feed - need to save the questions object for send it when user pressed on it
 *
 *  @param appUserId    the friend's userID
 *  @param fromTime     get feeds not earlier than this date
 *  @param maxEvents    maximum number of events to receive
 *  @param completion   block with resuls - array of VioozerFeedItem objects
 *  @param failedBlock  failed block
 */
-(void) getFeedForAnotherUserID:(NSString*)appUserId FromTime:(NSDate*)fromTime maxEvents:(NSInteger)maxEvents withCompletionBlock:(void (^)(NSArray* arrQuestions))completion andFailedBlock:(void (^)())failedBlock;

///**
// *  call this function when user click on vioozer feed
// *
// *  @param feed the selected item
// *
// *  @return the corresponding view controller for received feed item or nil if some problem accured.
// */
//-(UIViewController*) userDidSelectFeedItem:(VioozerFeedItem*)feed;


/**
 *  push the feed item view controller on the given navigation controller
 *
 *  @param feed  the feed item to show the corresponding view controller
 *  @param navC the navigation controller to push the feed vc on it
 *
 *  @return true iff there is a view controller to present
 */
-(BOOL) pushFeedItem: (VioozerFeedItem*) feed onNavigationController:(UINavigationController*) navC;


/**
 *  present the feed item view controller
 *
 *  @param feed the feed item
 *
 *  @return true if there is a view controller to present
 */
-(BOOL) presentFeedItem: (VioozerFeedItem*) feed;



/**
 *  use it for update Vioozer when app received new user location
 *
 *  @param location - new user location
 */
-(void) updateLocation:(CLLocation*)location;


/**
 *  update details of application user once user loggedin
 *
 *  @param user VioozerUser object
 */
-(void) updateUser:(VioozerUser*)user;


/**
 *  show new view controller for ask new question - when user click on "Viooz-it"
 *
 *  @param title     title of event that you send question on it
 *  @param location  location of selected event
 *  @param arrNerby  array of nerby checkins
 *  @param eventTime the start time of selected event
 *  @param source    UI commponent that user pressed on - AskQuestionSourceUI enum
 *
 */
-(void) showAskQuestionViewControllerWithTitle:(NSString*)title location:(VioozerLocation*)location nerbyLocations:(NSArray*)arrNerby eventTime:(NSDate*)eventTime andSourceUI:(AskQuestionSourceUI)source __attribute__((unavailable("Use -showSelectLocationViewControllerWithTitle:location:nerbyLocations instead")));

/**
 *  show new view controller for select lolcation from nerby locations
 *
 *  @param title     title of event that you send question on it
 *  @param location  location of selected event
 *  @param arrNerby  array of nerby checkins
 *
 */
-(void) showSelectLocationViewControllerWithTitle:(NSString*)title
                                         location:(VioozerLocation*)location
                                   nerbyLocations:(NSArray*)arrNerby;

///**
// *  show ask question view controller with VioozerLocation object
// *
// *  @param vioozerLocation   all location details
// *
// */
//-(void) showAskQuestionViewControllerWithLocation:(VioozerLocation*)vioozerLocation;

-(void) showNewAnswerScreen;


-(void) showNewWriteAnswerScreen;


/**
 *  show view controller for free search location before ask question
 */
-(void) showSearchLocationForAskQuestion;

/**
 *  get the search viewcontroller in navigation controller in order to customize its presentation
 *  @note NOT recommended
 *
 *  @return the navigation controller with the search viewcontroller
 */
-(UINavigationController*) getSearchLocationForAskQuestionNavigationViewController;

/**
 *  get the UtMainScreen viewcontroller in navigation controller in order to customize its presentation
 *  @note NOT recommended
 *
 *  @return the navigation controller with the search viewcontroller
 */
-(UINavigationController*) getUtMainScreen;


/**
 *  get the count of thank you that the user got for his answers.
 *
 *@param block	will return the count of thankyous or negative number if error accured
 */
-(void) getThankyouCounterWithCompletionBlock:(void (^) (NSInteger ThankyouCount)) block ;



///**
// *  set the SDK language
// *	@note if no language was set (or if an unsupported language is given) the SDK will
// *			take the device language if supported, and if not it will English localization
// *
// *  @param languageCode a canonicalized IETF BCP 47 language identifier
// *
// *  @return true iff the given language is supported by the SDK
// */
//-(BOOL) setSDKLanguage:(NSString*) languageCode;


/**
 *	if called, all tutorials will be presented again
 */
-(void) resetTutorials;


/**
 *  @return true iff vioozer SDK has its initials values
 */
-(BOOL) vioozerIsReady;


/**
 *  @return the VioozerSDKEnviroment
 */
-(VioozerSDKEnvironment) vioozerSDKEnvironment;


-(NSString*) user;

/*App invites callback per each platform*/

typedef void (^facebookInviteCallback)();
typedef void (^whatsAppInviteCallback)();
typedef void (^mailInviteCallback)();
typedef void (^SMSInviteCallback)();

/*
 * this function defines the functions should being call when user want to share the app
 * @param fbInvite - function for invite the via favcebook
 * @param whatsappInvite - function for invite via whatsapp
 * @param mailInvite - function for invite via mail
 * @param smsInvite - function for invite via sms
 */

-(void) defineInvitesWithFacebook:(facebookInviteCallback)fbInvite andWhatsApp:(whatsAppInviteCallback)whatsappInvite andMail:(mailInviteCallback)mailInvite andSms:(SMSInviteCallback)smsInvite;


/*
 * this function defines the functions should being call when user want to share the app using Facebook (other platform are enabled by default)
 * @param fbInvite - function for invite the via favcebook
 */
- (void)defineInvitesWithFacebook:(facebookInviteCallback)fbInvite;

/*
 * print log file to screen
 */
-(NSString*)printFile;
@end
