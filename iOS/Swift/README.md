# Instructions

## Step 1 - Add an API Key
Add a Vioozer API Key to `AppDelegate.swift`, and uncomment the following line:

    //        let vioozerAPIKey = <Enter your app key here>

### Recommendations
* Run `pod update` in order to get the latest SDK and dependencies.
* Clean (`⇧⌘K`) the project. 

The app is now ready - You can ask questions, see incoming questions in the *My Activity* page and answer them. 


## Step 2 - Remote notifications
In order to receive remote notifications ("push messages"):

* Create an App Id and valid provision.
* Create an APNS certificate and send us a `.p12` file (if it's password-protected, please send the password as well).

* Uncomment the code below this comment in `AppDelegate.m`:

```
/////////////////////////////////////////////////////////////////////////////
///-- Uncomment below to enable remote notifications ("push") messages  --///
/////////////////////////////////////////////////////////////////////////////
```
