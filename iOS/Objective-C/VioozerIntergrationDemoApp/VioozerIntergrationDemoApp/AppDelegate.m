//
//  AppDelegate.m
//  VioozerIntergrationDemoApp
//
//  Created by Yedidya Reiss on 17/01/2017.
//  Copyright © 2017 Yedidya Reiss. All rights reserved.
//

#import "AppDelegate.h"
#import <VioozerAPI.h>
@import UserNotifications;

@interface AppDelegate () <VioozerAPIDelegate,UNUserNotificationCenterDelegate>

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // Vioozer SDK Initialization
    
//    NSString* vioozerAPIKey = <Enter your app key here>;
    [VIOOZER_API initializeVioozerApiWithKey: vioozerAPIKey
                                    delegate: self
                           WithLaunchOptions: launchOptions
                                withLanguage: VioozerLanguageEnglish];
    
    /////////////////////////////////////////////////////////////////////////////
    ///-- Uncomment below to enable remote notifications ("push") messages  --///
    /////////////////////////////////////////////////////////////////////////////
    
    
//    if([UIDevice currentDevice].systemVersion.floatValue >= 10.0){
//        
//        UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
//        center.delegate = self;
//        
//        [center requestAuthorizationWithOptions:(UNAuthorizationOptionSound | UNAuthorizationOptionAlert | UNAuthorizationOptionBadge) completionHandler:^(BOOL granted, NSError * _Nullable error){
//            if( !error ){
//                [[UIApplication sharedApplication] registerForRemoteNotifications];
//            }
//        }];
//        
//        
//    }
//    else if ([[UIApplication sharedApplication] respondsToSelector:@selector(registerUserNotificationSettings:)]) {
//        
//        UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:(UIUserNotificationTypeBadge | UIUserNotificationTypeSound |UIUserNotificationTypeAlert) categories:nil];
//        
//        [[UIApplication sharedApplication] registerUserNotificationSettings:settings];
//    }
    
    return YES;
}


//- (void)application:(UIApplication *)app didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
//    [VIOOZER_API remoteNotificationDidRegisterDeviceToken:deviceToken];
//}
//
//
//
//
//-(void)application:(UIApplication *)application didRegisterUserNotificationSettings:(UIUserNotificationSettings *)notificationSettings {
//    
//    [[UIApplication sharedApplication] registerForRemoteNotifications];
//}
//
//
//
//-(void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
//    if ([userInfo[@"VIOOZER"] isEqualToString:@"VIOOZER"]) {
//        // Vioozer Push - Start
//        // Don't add any other code in this block
//        [VIOOZER_API receivedRemoteNotification:userInfo withApplicationState:application.applicationState andCompletionHandler:completionHandler];
//        // Vioozer Push - End
//    }
//    else {
//        // Handle Non-Vioozer push (regular app push messages).
//        // Add your code here, and leave the completionHandler call
//        // at the end of the block.
//        completionHandler(UIBackgroundFetchResultNewData);
//    }
//}
//
//
//#pragma mark - UIUserNotificationCenter delegate -
//
//-(void)userNotificationCenter:(UNUserNotificationCenter *)center
//      willPresentNotification:(UNNotification *)notification
//        withCompletionHandler:(void (^)(UNNotificationPresentationOptions options))completionHandler {
//    
//    NSDictionary* userInfo = notification.request.content.userInfo;
//    if ([userInfo[@"VIOOZER"] isEqualToString:@"VIOOZER"]) {
//        // Hanldes Vioozer SDK Push messages
//        [VIOOZER_API receivedRemoteNotification:userInfo withApplicationState:
//         [UIApplication sharedApplication].applicationState];
//        completionHandler(UNNotificationPresentationOptionBadge);
//    }
//    else {
//        // Hanldes the app push messages
//        completionHandler(UNNotificationPresentationOptionNone);
//    }
//}
//
//-(void)userNotificationCenter:(UNUserNotificationCenter *)center
//didReceiveNotificationResponse:(UNNotificationResponse *)response
//        withCompletionHandler:(void(^)())completionHandler {
//    
//    NSDictionary* userInfo = response.notification.request.content.userInfo;
//    if ([userInfo[@"VIOOZER"] isEqualToString:@"VIOOZER"]) {
//        
//        [VIOOZER_API receivedRemoteNotification:userInfo withApplicationState:
//         [UIApplication sharedApplication].applicationState andCompletionHandler:completionHandler];
//    }
//    else {
//        // Hanldes the app push messages
//        completionHandler(UIBackgroundFetchResultNewData);
//    }
//}


@end
