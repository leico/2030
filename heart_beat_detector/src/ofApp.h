#pragma once

#include "ofMain.h"
#include "ofxFaceTracker.h"
#include "ofxOpenCv.h"
#include "ofxCv.h"
#include "ofxOsc.h"
#include "ofxGui.h"

#define HOST "192.168.0.111"
#define HOSTLOCAL "127.0.0.1"
#define PORT 12345

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    int guiTF = 1;
    float heartbeat;
    
    ofxPanel gui;
    ofxToggle fullscreen;
    ofxToggle showCursor;
    ofxToggle grid;
    ofxToggle test;
    ofxIntSlider window_id;
    ofxIntSlider near;
    ofxIntSlider far;
    
    ofxOscSender sender;
};
