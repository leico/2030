#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //OSC sender
    sender.setup(HOSTLOCAL, PORT);
    
    //GUI
    gui.setup();
    gui.add(fullscreen.setup("Fullscreen", false));
    gui.add(showCursor.setup("Show cursor", true));
    gui.add(grid.setup("grid", false));
    gui.add(test.setup("test", false));
    gui.add(window_id.setup("window id",   0,     0,  3));
    gui.add(near.setup("near",             255,   40,  255));
    gui.add(far.setup("far",             255,   40,  255));
}

//--------------------------------------------------------------
void ofApp::update(){
    //OSC sender
    ofxOscMessage m;
    m.setAddress("/heartbeat");
    m.addFloatArg(heartbeat);
    sender.sendMessage(m);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //GUI
    if (guiTF % 2 == 0) {
        ofSetColor(100, 100);
        ofRect(5, 5, 210, 700);
        gui.draw();
        ofShowCursor();
        ofSetColor(0);
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //GUI
    if (key == 'g') guiTF++;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
