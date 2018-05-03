//
//  scene2.hpp
//  openingTheme
//
//  Created by Marc Edwards on 14/02/2018.
//

#ifndef scene2_hpp
#define scene2_hpp

#include "ofxGui.h"
#include "Globals.hpp"
#include "Border.hpp"
#include "ofxUI.h"
#include "Tracking.hpp"


class Scene2 : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void exit();
    void storeFrame(ofxCvColorImage img, int camWidth, int camHeight);
    void setupCamera();
    
    Border border1 = Border(ofGetWidth()-200 , 100);
    Border border2 = Border(ofGetWidth()/3+50 , ofGetHeight()/2);
    Border border3 = Border(ofGetWidth()/3+50 , ofGetHeight()/2);
    
    //dtore a list of webcams
    vector<string> webcams;
    vector<ofVideoDevice> devices;
    
    //count captured video frames
    int videoFrameCount;
    
    int rectWidth, rectHeight;
    
    int camWidth, camHeight, camrescaleWidth, camrescaleHeight;
    
    int _SCREEN_WIDTH, _SCREEN_HEIGHT, _SCREEN_WIDTH_HALF, _SCREEN_HEIGHT_HALF, _SCREEN_WIDTH_QUARTER, _SCREEN_HEIGHT_QUARTER, _SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_EIGHTH;
    
    string dropdown, video1, vide1Desc, video2, video2Desc;
    
    ofImage noWebcam, noProcess;
    ofImage greenTick;
    
    bool drawTick;
    
    //file dialog
    ofFileDialogResult selectFilePath;
    
    string filePath;

    ofxUISuperCanvas *guiDropdown;
    ofxUIDropDownList *ddl;
    void guiEvent(ofxUIEventArgs &e);
    
    ofxButton selectFileBtn;
    ofxPanel guiWebcam, guiSelectFile, gui;
    ofxFloatSlider brightness;
    ofxFloatSlider contrast;
    ofxIntSlider minArea;
    ofxIntSlider maxArea;
    ofxIntSlider threshold, grayThreshold;
    ofxToggle enableSnapshot; //behaves like a boolean variable
    ofxToggle grayScaleToggle;
    ofxToggle grayThresholdToggle;
    ofxToggle contrastBrightnessToggle;
    
    ofxLabel one;
    
    ofVideoGrabber cam;
    ofPixels previous;
    ofImage diff, grayscaleDiff, store;
    ofPixels tmpPixels;
    
    ofxCvGrayscaleImage     grayCopy, gray;
    ofxCvColorImage         colorCopy;
    ofxCvGrayscaleImage     thresholdImage;
    
    // a scalar is like an ofVec4f but normally used for storing color information
    cv::Scalar diffMean;
    
    ofxCvContourFinder     contourFinder;
    
    Tracking tracking;
};

#endif /* scene2_hpp */
