#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  ofBackground(255);
  ofSetCircleResolution(200);

  width = ofGetWidth();
  height = ofGetHeight();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  // centering the coordinate system
  ofPushMatrix();
  ofTranslate(width/2, height/2);

  // firstcircle
  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(0, 0, 200);

  // second circle
  ofNoFill();
  ofSetColor(0);
  ofDrawCircle(0, 0, 250);



  ofPopMatrix();

  // top line
  ofDrawLine(400, 100, 400, 200);
  // bottom line
  ofDrawLine(400, 600, 400, 700);

  // half-circle on the right
  ofPolyline polyline1;
  ofPoint arcRight(400,400);
  polyline1.arc(arcRight,225,225,-90, 90, 200);
  polyline1.draw();

  // half-circle on the left
  ofPolyline polyline2;
  ofPoint arcLeft(400,400);
  polyline2.arc(arcLeft,300,300, 90, 270, 200);
  polyline2.draw();

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
