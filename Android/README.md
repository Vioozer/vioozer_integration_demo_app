# Instructions

## Step 1 - API Key

Add your API Key to `MainActivity.java`:

    // Replace "0", an intended compilation error, with your actual key
    private static final String API_KEY = 0;  

## Step 2 - Add the Firebase configuration file.
Add your `google-services.json` from the Firebase console (the file is auto-generated for every android project). In order to receive push notifications, the server key should be shared with Vioozer (however, the SDK would work without it for testing).

## Step 3 - Google Maps API Key
Add your Google Maps API Key to the Manifest.
