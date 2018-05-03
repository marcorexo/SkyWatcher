#pragma once

#include "Border.hpp"
#include "Globals.hpp"

class Scene1 : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void exit();

    
     int _SCREEN_WIDTH, _SCREEN_HEIGHT, _SCREEN_WIDTH_HALF, _SCREEN_HEIGHT_HALF, _SCREEN_WIDTH_QUARTER, _SCREEN_HEIGHT_QUARTER, _SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_EIGHTH;
    
    //display instruction on screen
    string whatTitle, whatIsIt, whyTitle, whyUseful, howTitle, howToUse, warning;
    
    ofImage scenario1, scenario2, scenario3;
    
    //border constructor takes width and height parameters
    Border border1 = Border(ofGetWidth()/1.4 , ofGetHeight()/5);
    Border border2 = Border(ofGetWidth()/3 , ofGetHeight()/1.5);
    Border border3 = Border(ofGetWidth()/3 , ofGetHeight()/2.5);
    Border border4 = Border(ofGetWidth()/3 , 176);
};

