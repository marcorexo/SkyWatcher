//
//  scene2.cpp
//  openingTheme_Copy
//
//  Created by Marc Edwards on 14/02/2018.
//

#include "scene2.hpp"

using namespace ofxCv;
using namespace cv;

void Scene2::setup() {
    
    //do not draw the green tick at the start
    drawTick = false;
    
    //initialize file path to store images
    filePath = "";

    tracking  = Tracking();
    
    ofSetVerticalSync(true);
    //cam.setup(320, 240);
    
    videoFrameCount = 1;

    _SCREEN_WIDTH = ofGetWidth();
    _SCREEN_HEIGHT = ofGetHeight();
    
    _SCREEN_WIDTH_HALF = ofGetWidth()/2;
    _SCREEN_HEIGHT_HALF = ofGetHeight()/2;
    
    _SCREEN_WIDTH_EIGHTH = ofGetWidth()/8;
    _SCREEN_HEIGHT_EIGHTH = ofGetHeight()/8;
    
    //preload images
    noWebcam.load("noWebcamFeed.png");
    noWebcam.resize(350, 280);
    
    noProcess.load("noSignal.png");
    noProcess.resize(350, 280);
    
    greenTick.load("greenTick.png");
    greenTick.resize(30, 30);
    
    //camera
    camrescaleWidth = 352;
    camrescaleHeight = 288;
    //camrescaleWidth = 480;  // try to grab at this size.
    //camrescaleHeight = 360;
    
    camWidth = 960;  // try to grab at this size.
    camHeight = 720;
    
    //cam.setup(camWidth, camHeight);
    
    dropdown = "Select webcam";
    video1 = "Webcam feed";
    video2 = "Processed feed";
    
    
    border1.setup();
    border2.setup();
    border3.setup();
    
    //we can now get back a list of devices.
    devices = cam.listDevices();
    
    ofSetVerticalSync(true);

    guiDropdown = new ofxUISuperCanvas("Select the Webcam from the dropdown list");
    guiDropdown->setPosition(_SCREEN_WIDTH -500, _SCREEN_HEIGHT_EIGHTH-30);
    //guiDropdown->setPosition(_SCREEN_WIDTH_EIGHTH+50, _SCREEN_HEIGHT_EIGHTH-30);
    guiDropdown->setWidth(350);
    guiDropdown->setColorOutline(ofColor(255,0,0));
    
    guiDropdown->addSpacer();
    for(int i=0; i<devices.size(); i++){
        webcams.push_back(devices[i].deviceName);
    }
    //webcams.push_back("ONE");
    //webcams.push_back("TWO");
    

    guiDropdown->setWidgetFontSize(OFX_UI_FONT_MEDIUM);
    
    ddl = guiDropdown->addDropDownList("Dropdown list", webcams);
    ddl->setAllowMultiple(true);
    ddl->setAutoClose(true);
    guiDropdown->autoSizeToFitWidgets();
    //gui->setDrawWidgetPadding(true);
    guiDropdown->disable();
    ofAddListener(guiDropdown->newGUIEvent, this, &Scene2::guiEvent);

    
    
    guiWebcam.setup();
    guiWebcam.add(grayScaleToggle.setup("Grayscale on/off", false));
    guiWebcam.add(contrastBrightnessToggle.setup("Adjust contrast/brightness", false));
    
    guiWebcam.add(brightness.setup("Brightness", 0.0f, 0.0f, 1.0f));
    guiWebcam.add(contrast.setup("Contrast", 0.0f, 0.0f, 1.0f));
    guiWebcam.add(grayThresholdToggle.setup("B/W image threhold", false));
    guiWebcam.add(grayThreshold.setup("Gray threshold", 5, 3, 255));
    guiWebcam.setPosition(_SCREEN_WIDTH_EIGHTH+10, _SCREEN_WIDTH_HALF+80);
    guiWebcam.setBorderColor(ofColor(100, 100, 255));
    
    
    guiSelectFile.setup();
    guiSelectFile.add(selectFileBtn.setup("<- Select folder"));
    guiSelectFile.setPosition(_SCREEN_WIDTH_EIGHTH+50, _SCREEN_HEIGHT_EIGHTH);
    //guiSelectFile.setPosition(_SCREEN_WIDTH -300, _SCREEN_HEIGHT_EIGHTH-30);
    guiSelectFile.setBorderColor(ofColor(255, 255,  100));
    
    gui.setup();
    gui.add(minArea.setup("Min size (no units)", 5, 3, 255));
    gui.add(maxArea.setup("Max size (no units)", 5, 3, 600));
    gui.add(threshold.setup("Reduce sensitivity", 0, 0, 255));
    gui.add(enableSnapshot.setup("enable snapshot", false));
    gui.setBorderColor(ofColor(100, 255,  100));
    gui.setPosition(_SCREEN_WIDTH_HALF+60, _SCREEN_WIDTH_HALF+80);
    
    //add label guides
    gui.add(one.setup("Start here", ""));
    one.setSize(50, 30);
    one.setPosition(_SCREEN_WIDTH_EIGHTH+50, _SCREEN_HEIGHT_EIGHTH-40);

    
    // imitate() will set up previous and diff
    // so they have the same size and type as cam
    imitate(previous, cam);
    imitate(diff, cam);
    
    //allocate images
    //cam.setup(camWidth, camHeight);
    
    colorCopy.allocate(camWidth, camHeight);
    gray.allocate(camrescaleWidth, camrescaleHeight);
    //grayCopy.allocate(camWidth, camHeight);
    grayCopy.resize(camrescaleWidth, camrescaleHeight);
    thresholdImage.allocate(camrescaleWidth, camrescaleHeight);
    
    //allocate ofImage data types
    store.allocate(camrescaleWidth, camrescaleHeight, OF_IMAGE_COLOR);
    diff.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
    //grayscaleDiff.allocate(camWidth, camHeight, OF_IMAGE_GRAYSCALE);
    grayscaleDiff.allocate(camrescaleWidth, camrescaleHeight, OF_IMAGE_GRAYSCALE);
    
    // imitate() will set up previous and diff
    // so they have the same size and type as cam
    imitate(previous, cam);
    imitate(diff, cam);
    
    
}


void Scene2::update() {
    
    /*
     cam        - raw webcam image camWidth = 960; camHeight = 720;
     colorCopy  - ofxCvColorImage copy of cam image with the same resoluiton  camWidth = 960; camHeight = 720;
     gray       - ofxCvGrayscaleImage copy of colorCopy which is then rescaled ;  camresizeWidth = 352, camresizeHeight =  288;
     
     diff       - ofImage color; stores a difference image between current and previous image camWidth = 960; camHeight = 720;
     grayscaleDiff - ofImage gray; copies the diff image into a grayscale data type camWidth = 960; camHeight = 720;
     grayCopy   - copies the grayscaleDiff image camWidth = 960; camHeight = 720;
     */
    
    //   |
    //   |
    //   V
    
    //to do
    /*
     cam        - raw webcam image camWidth = 960; camHeight = 720;
     colorCopy  - ofxCvColorImage copy of cam image with the same resoluiton  camWidth = 960; camHeight = 720;
     gray       - ofxCvGrayscaleImage copy of colorCopy which is then rescaled ;  camresizeWidth = 352, camresizeHeight =  288;
                (to show the grayscale webcam image)
     
     diff       - ofImage color; stores a difference image between current and previous image camWidth = 960; camHeight = 720;
     *rescale the diff image*
     grayscaleDiff - ofImage gray; copies the diff image into a grayscale data type camWidth = 960; camHeight = 720;
     grayCopy   - copies the grayscaleDiff image **camresizeWidth = 352, camresizeHeight =  288;
     */
    
    
    //store raw image if the checkbox is ticked
    if (selectFileBtn){
        selectFilePath = ofSystemLoadDialog("Select a file path", true);
        
        //Check if the user opened a file
        if (selectFilePath.bSuccess){
            filePath = selectFilePath.getPath();
            drawTick = true;
        }else {
            //ofLogVerbose("User hit cancel");
        }
    }
    
    cam.update();
    if(cam.isFrameNew() and webcamSelected==true) {
        
        //copy the raw cam image into an ofxCvColorImage
        colorCopy.setFromPixels(cam.getPixels());
        
        //void ofSystemAlertDialog(string errorMessage)
        if(enableSnapshot == true and contourFinder.nBlobs > 0){
            storeFrame(colorCopy, camWidth, camHeight);
        }
        
        //colorCopy.resize(352, 288);
        colorCopy.resize(camrescaleWidth, camrescaleHeight);
        gray = colorCopy;
        
        if(grayThresholdToggle == true){
            gray.threshold(grayThreshold);
        }
        
        if(contrastBrightnessToggle){
            gray.brightnessContrast(brightness, contrast);
        }
        
        //use the grayscale image to calc the difference image
        
        // take the absolute difference of prev and cam and save it inside diff
        absdiff(cam, previous, diff);
        diff.update(); //called to update the rendered texture after changing the image pixels
        diff.resize(camrescaleWidth, camrescaleHeight);
        
        //clone the difference pixels into a new ofxCvGrayscaleImage
        grayscaleDiff.clone(diff);
        grayscaleDiff.setImageType(OF_IMAGE_GRAYSCALE);
        //grayscaleDiff.resize(352, 288);
        
        //copy the data structure
        grayCopy.setFromPixels(grayscaleDiff.getPixels());
        //grayCopy.blur(3);
        //grayCopy.dilate_3x3();
        //threshold the image to adjust sensitivity -> binary image
        
        /*
        if(grayScaleToggle){
            contrastBrightnessToggle.setup(true);
            if(grayThresholdToggle){
                gray.threshold(threshold);
            }
            gray.brightnessContrast(brightness, contrast);
        }
        */
        
        
        //threshold the grayscale diff image for sensitivity
        grayCopy.threshold(threshold);
        
        //finds all blobs in the image
        contourFinder.findContours(grayCopy, minArea, maxArea, 1, false, false);
        
        if(contourFinder.nBlobs > 0) tracking.update(contourFinder);
        

        
        // like ofSetPixels, but more concise and cross-toolkit
        copy(cam, previous);
    }
    
}

void Scene2::draw() {

    ofPushMatrix();
        ofTranslate(_SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_EIGHTH-60);
        ofSetColor(ofColor(200, 200,  50));
        ofDrawBitmapString(dropdown, 20, 0);
        border1.draw();
    ofPopMatrix();
    
    ofPushMatrix();
        ofTranslate(_SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_HALF-200);
        ofSetColor(ofColor(100, 100,  255));
        ofDrawBitmapString(video1, 20, 0);
        border2.draw();
    ofPopMatrix();
    
    ofSetColor(255);
    
    if(webcamSelected == false){
        noWebcam.draw(_SCREEN_WIDTH_EIGHTH+30,_SCREEN_HEIGHT_HALF - 170);
        noProcess.draw(_SCREEN_WIDTH_HALF+80, _SCREEN_HEIGHT_HALF-170);
    }
    
    if(webcamSelected){
        //cam.draw(_SCREEN_WIDTH_EIGHTH+30,_SCREEN_HEIGHT_HALF - 150);
        if(grayScaleToggle == false){
            colorCopy.draw(_SCREEN_WIDTH_EIGHTH+30,_SCREEN_HEIGHT_HALF - 150);
        }
        else{
            gray.draw(_SCREEN_WIDTH_EIGHTH+30,_SCREEN_HEIGHT_HALF - 150);
        }
        grayCopy.draw(_SCREEN_WIDTH_HALF+80, _SCREEN_HEIGHT_HALF-150);
        contourFinder.draw(_SCREEN_WIDTH_HALF+80, _SCREEN_HEIGHT_HALF-150);
    }
    
    ofPushMatrix();
        ofTranslate(_SCREEN_WIDTH_HALF+50, _SCREEN_HEIGHT_HALF-200);
        ofSetColor(ofColor(100, 255,  100));
        ofDrawBitmapString(video2, 20, 0);
        border3.draw();
    ofPopMatrix();

    ofSetColor(255);
    

    //guiWebcam.draw()
    guiSelectFile.draw();
    gui.draw();
    guiWebcam.draw();
    
    
    tracking.draw();
    
    if(drawTick == true){
        greenTick.draw(_SCREEN_WIDTH_EIGHTH+200, _SCREEN_HEIGHT_EIGHTH-40);
    }
    
}

int errorCount = 0;
void Scene2::storeFrame(ofxCvColorImage img, int camWidth, int camHeight){
    //set the path to save the captured frames with a timestamp
    string path = "";
    if(filePath != ""){
        path = filePath + "/" + ofGetTimestampString() + ".jpg";
    }
    else{
        if(errorCount < 1) ofSystemAlertDialog("Please select a folder to save the images");
    }
    
    errorCount ++;

    //then convert the new image to an ofImage so that it can be saved using ofSaveImage
    store.setFromPixels(img.getPixels());
    ofSaveImage(store, path);
}

//--------------------------------------------------------------
void  Scene2::guiEvent(ofxUIEventArgs &e)
{
    string name = e.widget->getName();
    if(name == "Dropdown list")
    {
        ofxUIDropDownList *ddlist = (ofxUIDropDownList *) e.widget;
        vector<ofxUIWidget *> &selected = ddlist->getSelected();
        for(int device = 0; device < selected.size(); device++)
        {
            deviceSelect = device;
        }
    }
    setupCamera();
}

void Scene2::setupCamera(){
    webcamSelected = true;
    
    noWebcam.clear();
    noProcess.clear();
    
    cam.setDeviceID(deviceSelect);
    cam.setDesiredFrameRate(60);
    cam.initGrabber(camWidth, camHeight);
}


void Scene2::exit(){
    //release pointer to tracking object
}



