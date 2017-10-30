#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    totalRays = 20;
    stepSize = 200;
    radius = 300;
    angleStep = TWO_PI/totalRays;
    sunLocX = ofGetWidth()/2;
    sunLocY = ofGetHeight()/2;
    ofSetCircleResolution(60);
    
    for(int i=0 ; i < totalRays ; i++) {
        noiseSeeds.push_back(ofRandom(10000));
    }
    
    ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(0, 30);
    if(mouseX != 0 || mouseY != 0) {
        sunLocX += (mouseX-sunLocX) * 0.01;
        sunLocY += (mouseY-sunLocY) * 0.01;
    }

    ofTranslate(sunLocX, sunLocY);
    
    ofScale(0.6, 0.6);
    
    
    
    
    ofBeginShape();
    
    float noiseRadius;
    ofPoint pointLocation;
    noiseRadius = (ofNoise(noiseSeeds[totalRays-1]) * stepSize) + radius;
    pointLocation.x = noiseRadius * cos(angleStep*(totalRays-1));
    pointLocation.y = noiseRadius * sin(angleStep*(totalRays-1));
    ofCurveVertex(pointLocation);
    for(int i=0 ; i<totalRays+1 ; i++) {
        if(i == totalRays) {
            noiseRadius = (ofNoise(noiseSeeds[0]) * stepSize) + radius;
        } else {
            noiseRadius = (ofNoise(noiseSeeds[i]) * stepSize) + radius;
        }
        pointLocation.x = noiseRadius * cos(angleStep*i);
        pointLocation.y = noiseRadius * sin(angleStep*i);
        ofCurveVertex(pointLocation);
        noiseSeeds[i] += 0.01;
    }
    noiseRadius = (ofNoise(noiseSeeds[noiseSeeds.size()]) * stepSize) + radius;
    pointLocation.x = noiseRadius * cos(angleStep*(noiseSeeds.size()));
    pointLocation.y = noiseRadius * sin(angleStep*(noiseSeeds.size()));
    ofCurveVertex(pointLocation);
    ofEndShape();
    
//    ofSetColor(255, 215, 13);
//    ofDrawCircle(0, 0, 300);
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
