//
//  Tracking.hpp
//  openingTheme
//
//  Created by Marc Edwards on 22/02/2018.
//

#ifndef Tracking_hpp
#define Tracking_hpp

#include "Globals.hpp"

class Tracking : public ofBaseApp{
    
public:
    void setup();
    void update(ofxCvContourFinder &contourFinderCopy);
    void draw();
    
    int nBlobs;
    
    int _SCREEN_WIDTH, _SCREEN_HEIGHT, _SCREEN_WIDTH_HALF, _SCREEN_HEIGHT_HALF, _SCREEN_WIDTH_QUARTER, _SCREEN_HEIGHT_QUARTER, _SCREEN_WIDTH_EIGHTH, _SCREEN_HEIGHT_EIGHTH;
    
    ofPoint point; //store blob centroids
    
    ofRectangle rectangle;
    
    ofxCvContourFinder     contourFinder;
    int blobWidth, blobHeight;
    
};

#endif /* Tracking_hpp */
