//
//  Tracking.cpp
//  openingTheme
//
//  Created by Marc Edwards on 22/02/2018.
//

#include "Tracking.hpp"

//takes the contour object from scene2 and processes it


void Tracking::setup() {
    nBlobs = 0;
    
    _SCREEN_WIDTH = ofGetWidth();
    _SCREEN_HEIGHT = ofGetHeight();
    
    _SCREEN_WIDTH_HALF = ofGetWidth()/2;
    _SCREEN_HEIGHT_HALF = ofGetHeight()/2;
    
    _SCREEN_WIDTH_EIGHTH = ofGetWidth()/8;
    _SCREEN_HEIGHT_EIGHTH = ofGetHeight()/8;
}

void Tracking::update(ofxCvContourFinder &contourFinderCopy) {
    //contourFinder = contourFinderCopy;

    point = {0, 0, 0};
    
    //used to reshape the bounding rectangle
    blobWidth = contourFinderCopy.getWidth();
    blobHeight = contourFinderCopy.getHeight();

    nBlobs = contourFinderCopy.nBlobs;
    if(nBlobs > 0){
        for(int i=0; i<nBlobs; i++ ){
            //collate average BLOB coorinates
            //cout << contourFinderCopy.blobs[i].centroid << endl;
            point += contourFinderCopy.blobs[i].centroid;
            //rectWidth = rectWidth + contourFinder.blobs[i].boundingRect.getHeight();
            //rectHeight = rectHeight + contourFinder.blobs[i].boundingRect.getWidth();
        }
    }
    
    if(nBlobs > 1){
        point.x = point.x/nBlobs;
        point.y = point.y/nBlobs;
    }
    
    //average height
    //rectWidth = rectWidth/contourFinder.nBlobs;
    //rectHeight = rectHeight/contourFinder.nBlobs;
}

void Tracking::draw() {
     //if(nBlobs > 0){ //draw circle at the blob coordinate
         //cam.draw(_SCREEN_WIDTH_EIGHTH+30,_SCREEN_HEIGHT_HALF - 150);
        //ofDrawRectangle(_SCREEN_WIDTH_EIGHTH + 100 + point.x, _SCREEN_HEIGHT_HALF+150 + point.y, 50, 50);
     //}
}
