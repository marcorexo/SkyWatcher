//
//  Border.cpp
//  openingTheme
//
//  Created by Marc Edwards on 14/02/2018.
//

#include "Scene1.hpp"


//--------------------------------------------------------------
void Scene1::setup(){
    
    _SCREEN_WIDTH = ofGetWidth();
    _SCREEN_HEIGHT = ofGetHeight();
    
    _SCREEN_WIDTH_HALF = ofGetWidth()/2;
    _SCREEN_HEIGHT_HALF = ofGetHeight()/2;
    
    _SCREEN_WIDTH_QUARTER = ofGetWidth()/4;
    _SCREEN_HEIGHT_QUARTER = ofGetHeight()/4;
    
    _SCREEN_WIDTH_EIGHTH = ofGetWidth()/8;
    _SCREEN_HEIGHT_EIGHTH = ofGetHeight()/8;
    
    whatTitle = "What is SkyWatcher";
    whatIsIt = "SkyWatcher is a motion detector and tracker designed for astronomers and general UFO\nenthusiasts. It can be used in the daytime or at night, with a normal or infrared webcam,\nas long as your computer detects the webcam.\n\nSkyWatcher detects movement in the video feed and stores the snapshot in the folder\nof your choice. It is designed to help you avoid missing fast moving objects or\nphenomena in the sky. This tool will assist your capture of astronomical or atmospheric\nphenomena without having to sit for hours in front of the screen.\n";

    whyTitle = "When to use SkyWatcher";
    whyUseful = "(i) Shooting stars & bright objects;\n(ii) birds, aricraft, fast clouds & other\natmospheric phenomena.";
    
    howTitle = "Setup the software";
    howToUse = "You can use a normal or modified webcam\nsuch as an infrared webcam. The process\nof setting up SkyWatcher should be\ncarried out in the following way:\n\n\n(i)   Select the webcam on your system.\n\n(ii)  Adjust the size threshold for the\nobject to be detected. If you are unsure\nabout this you can ramp this\nvalue up to maximum.\n\n(iii) Adjust the sensitivity threshold.\n\n(iv)  Select the folder for storing\n snapshot images\n\n(v)   Click on the start button\nand make yourself a cup of tea.";
    
    warning = "Interference from shrubs in the wind or\nvibrating the camra should be avoided.";

    border1.setup();
    border2.setup();
    border3.setup();
    border4.setup();
    
    //vector<ofxUIWidget*> spacers = gui->getWidgetsOfType(OFX_UI_WIDGET_SPACER);
    
    //load test image
    scenario1.load("scenario1.png");
    scenario1.resize(300,195);
    
    scenario2.load("scenario2.png");
    scenario2.resize(300,195);

    scenario3.load("scenario3.png");
    scenario3.resize(300,115);

    
}

//--------------------------------------------------------------
void Scene1::update(){

}

//--------------------------------------------------------------
void Scene1::draw(){
    ofSetColor(ofColor(200, 200, 50));
    if(GScene1 == true){
        ofPushMatrix();
            ofTranslate(_SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_EIGHTH-60);
            border1.draw();
            ofDrawBitmapString(whatTitle, 20, 0);
            ofSetColor(ofColor(255, 255, 255));
            ofDrawBitmapString(whatIsIt, 20, 40);
        ofPopMatrix();
        
        ofSetColor(ofColor(100, 100,  255));
        ofPushMatrix();
            ofTranslate(_SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_HALF-155);
            ofDrawBitmapString(whyTitle, 20, 0);
            border2.draw();
            ofSetColor(ofColor(255, 255, 255));
            ofDrawBitmapString(whyUseful, 20, 40);
            //scenario1.draw(30,100);
            //scenario2.draw(30,320);
        ofPopMatrix();
        
        ofSetColor(ofColor(100, 255,  100));
        ofPushMatrix();
            ofTranslate(_SCREEN_WIDTH_HALF, _SCREEN_HEIGHT_HALF-155);
            border3.draw();
            ofDrawBitmapString(howTitle, 20, 0);
            ofSetColor(ofColor(255, 255, 255));
            ofDrawBitmapString(howToUse, 20, 40);
        ofPopMatrix();
        
        ofSetColor(ofColor(255, 50, 50));
        ofPushMatrix();
            ofTranslate(_SCREEN_WIDTH_HALF, _SCREEN_HEIGHT_HALF+180);
            border4.draw();
            ofSetColor(ofColor(255, 255, 255));
            ofDrawBitmapString(warning, 20, 40);
            //scenario3.draw(30,63);
        ofPopMatrix();
        
        ofSetColor(ofColor(255, 255, 255));
    }
}

void Scene1::exit(){
}


