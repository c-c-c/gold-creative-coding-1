#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetCircleResolution(50);
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    int numOfRadarsX = 10;
    int numOfRadarsY = 10;

    int bigDiam = ofGetWidth()/numOfRadarsX/2;
    int startX = bigDiam/2;
    int startY = bigDiam/2;
    int smallDiam = bigDiam/2;

    for (int x=startX; x<ofGetWidth(); x+=bigDiam){
      for (int y=startY; y<ofGetWidth(); y+=bigDiam){
           float angle = ofMap(x+y+ofGetFrameNum()*5, 0, ofGetWidth() + ofGetHeight(), 0, 720);
           drawRadar(x,y,bigDiam,smallDiam,angle);
        }
    }

}
//--------------------------------------------------------------
void ofApp::drawRadar(int locX, int locY, int bigD, int smallD, float angle){
    ofPushMatrix();
    ofTranslate(locX, locY);
    ofNoFill();
    ofSetColor(0);
    ofDrawEllipse(0, 0, bigD, bigD);
    ofRotate(angle);
    ofTranslate(bigD/2,0);
    ofFill();
    ofDrawEllipse(0,0,smallD, smallD);
    ofPopMatrix();
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
