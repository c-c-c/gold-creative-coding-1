#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(30);
    vidGrabber.initGrabber(320, 240);
    maxBufferSize = ofGetWidth();
}


//--------------------------------------------------------------
void ofApp::update(){
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew())
    {
        //add to buffer
        ofImage img;
        img.setFromPixels(vidGrabber.getPixels());
        img.mirror(false, true); // if you want to mirror input
        imgBuffer.push_front(img);
    }
    
    //remove from back if buffer has reached maximum size
    if (imgBuffer.size()>maxBufferSize) imgBuffer.pop_back();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    if (imgBuffer.size()>=1)
    {
//        imgBuffer[imgBuffer.size()-1].draw(0,0);
//        ofSetColor(255, 255, 255);
        imgBuffer[0].draw(0,0);
    }
    
    int slitLocX = vidGrabber.getWidth()/2;
    int slitLocY = vidGrabber.getHeight();
    
    ofSetColor(255, 0, 0);
    ofSetLineWidth(3.0);
    ofDrawLine(slitLocX, 0, slitLocX, slitLocY);
    
    ofSetColor(255, 255, 255);
    
    for (int i=0; i<imgBuffer.size(); i++) {
        imgBuffer[i].drawSubsection(i, vidGrabber.getHeight(), 1.0, vidGrabber.getHeight(), vidGrabber.getWidth()/2, 0);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
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
