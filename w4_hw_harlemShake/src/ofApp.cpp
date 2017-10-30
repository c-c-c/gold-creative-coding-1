#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  ofBackground(0);

  stepSize = 20;
  goCrazy = false;

  spacingX = ofGetWidth() / numX;
  spacingY = ofGetHeight() / numY;

  startingX = spacingX / 2;
  startingY = spacingY / 2;

  for (int x = 0; x < numX; x++) {
    for (int y = 0; y < numY; y++) {

    noiseSeeds[x][y] = ofRandom(1000);

    }
  }

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  ofSetColor(0, 20);
  ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

  ofSetColor(255);

  if (!goCrazy) {

  for (int i = 0; i < numX; i++) {
    for (int j = 0; j < numY; j++) {

      float sum = stepSize * ofSignedNoise(noiseSeeds[i][j]);

      int locX = startingX + spacingX*i + sum;
      int locY = startingY + spacingY*j + sum;

      ofDrawCircle(locX, locY, 3);




    }
  }

} // goCrazy



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

    // flips back and forth between true and false
    goCrazy = !goCrazy;

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
