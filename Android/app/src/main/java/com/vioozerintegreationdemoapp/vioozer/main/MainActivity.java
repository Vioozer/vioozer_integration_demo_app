package com.vioozerintegreationdemoapp.vioozer.main;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.vioozer.vioozerintegreationdemoap.R;
import com.vioozer.vioozersdk.VioozerAPI;
import com.vioozer.vioozersdk.interfaces.VioozerEventListener;
import com.vioozer.vioozersdk.location.VioozerLocation;
import com.vioozer.vioozersdk.util.MultipleLocationsException;
import com.vioozer.vioozersdk.util.VioozerLanguage;

import java.util.ArrayList;

public class MainActivity extends Activity implements View.OnClickListener {
    VioozerAPI vioozer;
    private TextView mInitializationTV;
    private Button mMyActivityBTN, mMyAskAQuestionBTN;
    private View mInitializationUnderLineView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initUI();

        //VIOOZER SDK  initialization
        vioozer = VioozerAPI.sharedInstance(this);


/* Contact adam@vioozer.com for an API Key! */
        vioozer.initialize(0, new VioozerEventListener() {
            @Override
            public void OnVioozerFinishedInitialized() {

                mInitializationTV.setText(R.string.initialization_ok);
                mInitializationTV.setTextColor(Color.GREEN);
                mInitializationUnderLineView.setBackgroundColor(Color.GREEN);
            }
        }, VioozerLanguage.ENGLISH, "", this);
    }


    private void initUI() {

        //initialize widgets
        mMyActivityBTN = (Button) findViewById(R.id.myActivityBTN);
        mMyAskAQuestionBTN = (Button) findViewById(R.id.askAQuestionBTN);
        mInitializationTV = (TextView) findViewById(R.id.initializationTV);
        mInitializationUnderLineView = (View) findViewById(R.id.initializationUnderLineView);

        //initialize onClickListener
        mMyActivityBTN.setOnClickListener(this);
        mMyAskAQuestionBTN.setOnClickListener(this);
    }


    //opening my feed Activity
    private void openFeed() {

        vioozer.openMyActivity();
    }

    //opening ask a question screen
    private void openAskAquestionScreen() {
        VioozerLocation.VioozerLocationBuilder builder = new VioozerLocation.VioozerLocationBuilder();
        VioozerLocation firstPlace = builder
                .latitude(37.7329743).longitude(-122.5028407).
                        build();
        ArrayList<VioozerLocation> locations = new ArrayList<>();
        locations.add(firstPlace);
        try {
            vioozer.showAskMultipleQuestionsActivity(locations, null, false);
        } catch (MultipleLocationsException e) {
            e.printStackTrace();
        }

    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.myActivityBTN:
                openFeed();
                break;
            case R.id.askAQuestionBTN:
                openAskAquestionScreen();
                break;
        }

    }
}
