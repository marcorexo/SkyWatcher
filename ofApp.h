/*
 Annimated opening theme that explains how the software works
 1. Opening theme explaining what SkyCatcher is about
    a. black backgroud
    b. divided sections made to look space age / scifi like on star trek
    c. button for next -> moves sections / partitions aside to reveal the next scene
 */
#pragma once

#include <stdio.h>
#include "ofMain.h"
#include "Scene1.hpp"
#include "scene2.hpp"
#include "ofxGui.h"
#include "Globals.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        //void mouseMoved(int x, int y );
    
    int _SCREEN_WIDTH, _SCREEN_HEIGHT, _SCREEN_WIDTH_HALF, _SCREEN_HEIGHT_HALF, _SCREEN_WIDTH_QUARTER, _SCREEN_HEIGHT_QUARTER, _SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_EIGHTH;
    
    ofImage logo;
    
    ofImage scenario1, scenario2, scenario3;
    
    ofxPanel gui;
    ofxButton nextScene, backScene;

    Scene1 scene1;
    Scene2 scene2;
    
    
    bool switch_;
};
