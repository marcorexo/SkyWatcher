//
//  Border.hpp
//  openingTheme
//
//  Created by Marc Edwards on 14/02/2018.
//

#ifndef Border_hpp
#define Border_hpp

#include "ofMain.h"

 /* Border_hpp */

class Border : public ofBaseApp{
    
private:
    int height;
    int width;
    
public:
    void setWidth(int width);
    void setHeight(int height);
    void setup();
    void update();
    void draw();
    
    
    ofRectangle myRect;
    ofColor color;
    
    Border(int width, int height); //constructor
};

#endif
