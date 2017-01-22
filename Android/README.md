# Instructions

## Step 1 - API Key

Add your API Key to `MainActivity.java`:

    // Replace "0", an intended compilation error, with your actual key
    private static final String API_KEY = 0;  

## Step 2 - Add the Firebase configuration file.

Add a `google-services.json` file from the Firebase console to the project. In order to receive push notifications, the server key from the console should be sent to Vioozer (however, the SDK would work without it for testing).

## Step 3 - Google Maps API Key
Add your Google Maps API Key to the Manifest. The key is required in order to display a map when creating or answering a question.

## Step 4 - Customize

Follow [our online documentation](https://developer.vioozer.com/android.html) to customize the SDK. For example, you can:

* Create a question with a place name and address
* Ask a question on multiple locations
* Get the number of unread items in the user activity stream
