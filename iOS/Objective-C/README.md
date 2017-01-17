# Instructions

## Step 1 - Add an API Key
Add a Vioozer API Key to the `application:didFinishLaunchingWithOptions:` method, and uncomment the following line:

    //    NSString* vioozerAPIKey = <Enter your app key here>;


The app should be executable by now. You can ask questions, see incoming questions in the *My Activity* page and answer them. 

That's it! There's no step 2...

## Pod update - recommended
Run `pod update` in order to get the latest SDK and dependencies.

## Remote notifications - recommended
In order to receive remote notifications ("push messages"):

* Uncomment the code below this comment in `AppDelegate.m`:

```
/////////////////////////////////////////////////////////////////////////////
///-- Uncomment below to enable remote notifications ("push") messages  --///
/////////////////////////////////////////////////////////////////////////////
```

* Create an App Id and valid provision.
* Create an APNS certificate and send us a `.p12` file (if it's password-protected, please send the password as well).
