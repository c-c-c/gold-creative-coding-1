#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(36,41,73);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    waves();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ofImage screenshot;
    screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    screenshot.save("saved_"+ofGetTimestampString()+".png");
    
}

//--------------------------------------------------------------
void ofApp::waves(){
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    frameCount = ofGetFrameNum();
    
    t = (float) frameCount/maxFrameCount;
    
    theta = TWO_PI*t;
    
    for ( int x= -175; x <= 175; x += 25) {
        for (int y= -100; y <= 155; y += 50) {
            float offSet = 50*x+y+y;
            float x2 = ofMap(cos(-theta+offSet), 0, 1, 0, 25);
            float y2 = ofMap(cos(-theta+offSet), 0, 1, 25, 0);
            float sz2 = ofMap(sin(-theta+offSet), 0, 1, 15, 45);
            
            ofSetColor(250-(x/2), 150+(x/6), 250-(y/2));
            
            ofDrawEllipse(x+x2, y-y2, sz2, sz2);
        }
    }
}

