#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	//ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context
    //glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);   //keep window same size
    //glfwSetWindowSize(<#GLFWwindow *window#>, <#int width#>, <#int height#>)
    
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
    
    
    //this longer method allows me to stop window resize
    ofGLFWWindowSettings settings;
    settings.resizable = false;
    settings.width = 1024;
    settings.height = 768;
    settings.setPosition(ofVec2f(300,10));
    
    auto mainWindow = ofCreateWindow(settings);
    
    auto mainApp = make_shared<ofApp>();
    
    ofRunApp(mainWindow, mainApp);
    ofRunMainLoop();
	//ofRunApp(new ofApp());

}
