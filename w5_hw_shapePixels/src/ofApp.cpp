#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(640, 480);
    spacing = 10;
    startPos = spacing/2;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    pixels = vidGrabber.getPixels();
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    if(mode ==1) {
        for(int i=0; i<ofGetWidth()/spacing; i++) {
            for(int j=0; j<ofGetHeight()/spacing; j++) {
                int locX = spacing;
                int locY = spacing;
                ofColor c = pixels.getColor(locX*i+startPos, locY*j+startPos);
                int brightness = c.getBrightness();
                //int maxSize = 10;
                int maxSize = ofMap(mouseX, 0, ofGetHeight(), 0, spacing*2);
                float radius = ofMap(brightness,0,255,maxSize,0);
                ofPushMatrix();
                ofTranslate(locX*i+startPos, locY*j+startPos);
                ofSetColor(c);
                ofDrawCircle(0, 0, radius);
                ofPopMatrix();
            }
        }
//    }
    
    }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == 's') {
        ofImage screenshot;
        screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        screenshot.save("saved_"+ofGetTimestampString()+".png");
    }
    
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
