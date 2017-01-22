//
//  AppDelegate.swift
//  VioozerSwiftDemoApp
//
//  Created by Yedidya Reiss on 17/01/2017.
//  Copyright © 2017 Yedidya Reiss. All rights reserved.
//

import UIKit
import UserNotifications

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, VioozerAPIDelegate, UNUserNotificationCenterDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        
        // Vioozer SDK Initialization
//        let vioozerAPIKey = <Enter your app key here>
        VioozerAPI.sharedInstance().initializeVioozerApi(withKey: vioozerAPIKey, delegate: self, withLaunchOptions: launchOptions, with: VioozerLanguageEnglish)
        
        
        /////////////////////////////////////////////////////////////////////////////
        ///-- Uncomment below to enable remote notifications ("push") messages  --///
        /////////////////////////////////////////////////////////////////////////////
        
//        
//        if #available(iOS 10.0, *) {
//            let center = UNUserNotificationCenter.current()
//            center.delegate = self
//            center.requestAuthorization(options:[.badge, .alert, .sound]) { (granted, error) in
//                application.registerForRemoteNotifications()
//            }
//        }
//        else {
//            let setting = UIUserNotificationSettings(types: [.alert, .badge, .sound], categories: nil)
//            UIApplication.shared.registerUserNotificationSettings(setting)
//            UIApplication.shared.registerForRemoteNotifications()
//        }
        
        return true
    }

//    
//    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
//        VioozerAPI.sharedInstance().remoteNotificationDidRegisterDeviceToken(deviceToken)
//    }
//    
//    
//    func application(_ application: UIApplication, didReceiveRemoteNotification userInfo: [AnyHashable : Any], fetchCompletionHandler completionHandler: @escaping (UIBackgroundFetchResult) -> Void) {
//        
//        if let _ = userInfo["VIOOZER"] {
//            VioozerAPI.sharedInstance().receivedRemoteNotification(userInfo, with: application.applicationState, andCompletionHandler: completionHandler)
//        }
//        else {
//            // Handle Non-Vioozer push (regular app push messages).
//            // Add your code here, and leave the completionHandler call
//            // at the end of the block.
//            completionHandler(.newData);
//        }
//    }
//    
//    
//    // MARK: - UNUserNotificationCenterDelegate -
//    
//    
//    @available(iOS 10.0, *)
//    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
//        
//        let userInfo = notification.request.content.userInfo
//        
//        if let _ = userInfo["VIOOZER"] {
//            // Handles Vioozer SDK Push messages
//            VioozerAPI.sharedInstance().receivedRemoteNotification(userInfo, with: UIApplication.shared.applicationState)
//            completionHandler(.badge)
//        }
//        else {
//            // Handle Non-Vioozer push (regular app push messages).
//            // Add your code here, and leave the completionHandler call
//            // at the end of the block.
//            completionHandler(.badge)
//        }
//
//    }
//    
//    
//    @available(iOS 10.0, *)
//    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
//        
//        let userInfo = response.notification.request.content.userInfo
//        if let _ = userInfo["VIOOZER"] {
//            // Handles Vioozer SDK Push messages
//            let completion : (UIBackgroundFetchResult)->() = { (result) -> Void in completionHandler() } //a wrapper to the old completion block
//            VioozerAPI.sharedInstance().receivedRemoteNotification(userInfo, with: UIApplication.shared.applicationState, andCompletionHandler: completion)
//        }
//        else {
//            // Handle Non-Vioozer push (regular app push messages).
//            // Add your code here, and leave the completionHandler call
//            // at the end of the block.
//            completionHandler();
//        }
//    }
  
}


