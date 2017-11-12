#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

    for (int i=0; i<loc1X.size(); i++)
    {
        loc1X[i] += speed1X[i];
        loc1Y[i] += speed1Y[i];
        loc2X[i] += speed2X[i];
        loc2Y[i] += speed2Y[i];

        if (loc1X[i]>=ofGetWidth() || loc1X[i]<=0) {
            speed1X[i] *= -1;
        }
        if (loc1Y[i]>=ofGetHeight() || loc1Y[i]<=0) {
            speed1Y[i] *= -1;
        }
        if (loc2X[i]>=ofGetWidth() || loc2X[i]<=0) {
            speed2X[i] *= -1;
        }
        if (loc2Y[i]>=ofGetHeight() || loc2Y[i]<=0) {
            speed2Y[i] *= -1;
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i=0; i<loc1X.size(); i++)
    {
        ofSetColor(255,green[i],0,100);
        ofTriangle(loc1X[i], loc1Y[i], loc2X[i], loc2Y[i], mouseX, mouseY);
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
    if (button==0){
        loc1X.push_back(ofRandomWidth());
        loc1Y.push_back(ofRandomHeight());
        loc2X.push_back(ofRandomWidth());
        loc2Y.push_back(ofRandomHeight());
        speed1X.push_back(ofRandomf());
        speed1Y.push_back(ofRandomf());
        speed2X.push_back(ofRandomf());
        speed2Y.push_back(ofRandomf());
        green.push_back(ofRandom(255));
    }
    else {
        if (loc1X.size()>0) {
            loc1X.pop_back();
            loc1Y.pop_back();
            loc2X.pop_back();
            loc2Y.pop_back();
            speed1X.pop_back();
            speed1Y.pop_back();
            speed2X.pop_back();
            speed2Y.pop_back();
            green.pop_back();
        }
    }
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
