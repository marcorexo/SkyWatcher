#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //load logo
    
    _SCREEN_WIDTH = ofGetWidth();
    _SCREEN_HEIGHT = ofGetHeight();
    
    _SCREEN_WIDTH_HALF = ofGetWidth()/2;
    _SCREEN_HEIGHT_HALF = ofGetHeight()/2;
    
    _SCREEN_WIDTH_QUARTER = ofGetWidth()/4;
    _SCREEN_HEIGHT_QUARTER = ofGetHeight()/4;
    
    _SCREEN_WIDTH_EIGHTH = ofGetWidth()/8;
    _SCREEN_HEIGHT_EIGHTH = ofGetHeight()/8;
    
    ofSetBackgroundColor(0,0,0);
    
    ofSetWindowTitle("SkyWatcher");
    logo.load("logo3.png");
    
    //load test image
    scenario1.load("scenario1.png");
    scenario1.resize(300,195);
    
    scenario2.load("scenario2.png");
    scenario2.resize(300,195);
    
    scenario3.load("scenario3.png");
    scenario3.resize(300,115);
    
    scene1.setup();
    scene2.setup();
    
    gui.setup();
    gui.add(nextScene.setup("NEXT", false));
    gui.add(backScene.setup("BACK", false));
    gui.setPosition(10, ofGetHeight()/2);
    gui.setSize(60, 200);
    gui.setBorderColor(ofColor(0, 255, 255));
   
}

bool switch_ = true; //turn the dropdown menu in scene 2 on/off
//--------------------------------------------------------------
void ofApp::update(){
    if(nextScene == true){
        GScene1 = false;
    }
    if(backScene == true){
        GScene1 = true;
    }

    //show scene 2
    if(GScene1 == false){
        scene2.update();
        if(switch_ = true){
            scene2.guiDropdown->enable();
            switch_ = false;
        }
    }
    
    //show scene 1
    else if(GScene1 == true){
        if(switch_ = true){
            scene2.guiDropdown->disable();
            switch_ = false;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    logo.draw(10, 10);
    
    gui.draw();
    
    if(GScene1 == true){
        scene2.exit();
        scene1.draw();
        
        ofPushMatrix();
            ofTranslate(_SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_HALF-155);
            scenario1.draw(30,100);
            scenario2.draw(30,320);
        ofPopMatrix();
        
        ofPushMatrix();
            ofTranslate(_SCREEN_WIDTH_HALF, _SCREEN_HEIGHT_HALF+180);
            scenario3.draw(30,63);
        ofPopMatrix();
    }
    else{
        //ofSetBackgroundColor(255, 255, 255);
        scene1.exit();
        scene2.draw();
    }
}

/*
void ofApp::mouseMoved(int x, int y ){
    if(x > ofGetWidth() or x < 0 or y > ofGetHeight() or y < 0){
        ofHideCursor();
    }
    else{
        ofShowCursor();
    }
}
 */

