//
//  Border.cpp
//  openingTheme
//
//  Created by Marc Edwards on 14/02/2018.
//

#include "Border.hpp"

Border::Border(int w, int h){
    ofSetLineWidth(5);
    setWidth(w);
    setHeight(h);
}

void Border::setWidth(int width_){
    width = width_;
}

void Border::setHeight(int height_){
    height = height_;
}

//--------------------------------------------------------------
void Border::setup(){
    myRect.x = 10;
    myRect.y = 10;
    myRect.width = width;
    myRect.height = height;
}

//--------------------------------------------------------------
void Border::update(){
    
}

//--------------------------------------------------------------
void Border::draw(){
    ofNoFill();
    ofDrawRectRounded(myRect, 10);
}
