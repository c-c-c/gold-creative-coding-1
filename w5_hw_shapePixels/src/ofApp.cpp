#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    spacing = 10;
    startPos = spacing/2;
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(ofGetWidth(), ofGetHeight());
    
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    pixels = vidGrabber.getPixels();

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(255, 255, 255);
    
    for (int i=0; i<ofGetWidth()/spacing; i++) {
        for (int j=0; j<ofGetHeight()/spacing; j++) {
            
            int locX = startPos + spacing*i;
            int locY = startPos + spacing*j;

            ofColor c = pixels.getColor(i, j);
            
            int brightness = c.getBrightness();
            
            int maxSize = 10;
            float radius = ofMap(brightness, 0, 255, maxSize, 0);
            
            ofSetColor(c);
            ofDrawCircle(locX, locY, radius);
            
            
            

        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
