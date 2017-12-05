#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(200);

}

//--------------------------------------------------------------
void ofApp::update(){

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    numberOfCircles = 10;
    
    int spacing;
    int maxLineWidth = 20;
    
    spacing = maxLineWidth;
    
    
    
    for (int i=0; i<numberOfCircles; i++) {
    
        

        float ripple = (sin(ofMap(ofNoise((ofGetFrameNum()+i*20)/100.0), 0, 1, 0, TWO_PI))+1)/2;
        
       
        
        circle(ripple, ofMap(ripple*i, 0, 1, 0, 255), i*spacing);
        
        
    }
    
}

//--------------------------------------------------------------
void ofApp::circle(float c, float a, float r) {

    ofPushMatrix();
    ofPushStyle();
    ofSetColor(255, a);
    ofNoFill();
    ofSetLineWidth(ofMap(c, 0, 1, 1.0, 10.0));
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofDrawCircle(0, 0, r);
    ofPopStyle();
    ofPopMatrix();
    
}
