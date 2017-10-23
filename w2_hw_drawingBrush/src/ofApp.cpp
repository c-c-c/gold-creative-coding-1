//--------------------------------------------------------------
// Celine Chappert
// 23 October 2017
// Assignment week 2 : Animated Brushes
//
// All code my own
//
// Keyboard shortcuts :
//
// g            show grid
// h            hide grid
// d            control direction
// up/down      line length if shape is a line
// left/right   speed
// q/a          ellipse radius
// backspace    clear
// s            save
// 1            drawing mode 1
// 2            drawing mode 2
// 3            drawing mode 3
//
//
// Comments below
//
//--------------------------------------------------------------

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

  ofBackground(ofColor::beige);
  ofSetBackgroundAuto(false);

  length = 0;
  angle = 0;
  angleSpeed = 1.0;
  radius = 700;

  showGrid = false;

  mode1 = true;
  mode2 = false;
  mode3 = false;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


  if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT) || ofGetMousePressed(OF_MOUSE_BUTTON_RIGHT)) {

  ofPushMatrix();

  ofSetLineWidth(1.0);
  ofNoFill();

  if (mode1) drawMode1();
  if (mode2) drawMode2();
  if (mode3) drawMode3();

  // ofSetColor(ofColor::midnightBlue);
  // ofNoFill();
  // ofTranslate(mouseX, mouseY);
  // ofRotate(angle);
  // ofDrawEllipse(0, 0, 50+length, radius);

  // ofDrawLine(0, 0, lineLength, 0);

  ofPopMatrix();

  angle += angleSpeed;

} // mouse pressed ends

// extra feature not working
if (showGrid) {
  for (int x = 0; x < ofGetWidth(); x+=10) {
    for (int y = 0; y < ofGetHeight(); y+=10) {

        ofNoFill();
        ofDrawCircle(x, y, 50);

    }
  }
}

}

//--------------------------------------------------------------
void ofApp::drawMode1(){
  ofSetColor(ofColor::midnightBlue);
  ofNoFill();
  ofTranslate(mouseX, mouseY);
  ofRotate(angle);
  ofDrawEllipse(0, 0, 50+length, radius);
}

//--------------------------------------------------------------
void ofApp::drawMode2(){
  ofSetColor(ofColor::darkRed);
  ofNoFill();
  ofTranslate(mouseX, mouseY);
  ofRotate(angle);
  ofDrawEllipse(0, 0, 50+length, radius);
}

//--------------------------------------------------------------
void ofApp::drawMode3(){
  ofSetColor(ofColor::seaGreen);
  ofNoFill();
  ofTranslate(mouseX, mouseY);
  ofRotate(angle);
  ofDrawEllipse(0, 0, 50+length, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

  // show/hide grid
  if (key == 'g') showGrid = true;
  if (key == 'h') showGrid = false;

  // direction
  if (key == 'd') {
    angle = angle + 180;
    angleSpeed = angleSpeed * -1;
  }

  // line length
  if (key == OF_KEY_UP) length += 5;
  if (key == OF_KEY_DOWN) length -= 5;

  // ellipse radius
  if (key == 'q') radius += 50;
  if (key == 'a') radius -= 50;

  // speed
  if (key == OF_KEY_LEFT) angleSpeed -= 0.5;
  if (key == OF_KEY_RIGHT) angleSpeed += 0.5;

  // draw modes
  if (key == '1') {
    mode1 = true;
    mode2 = false;
    mode3 = false;
  }

  if (key == '2') {
    mode1 = false;
    mode2 = true;
    mode3 = false;
  }

  if (key == '3') {
    mode1 = false;
    mode2 = false;
    mode3 = true;
  }

  // clear
  if (key ==  OF_KEY_BACKSPACE || key == OF_KEY_RETURN) ofBackground(ofColor::beige);

  // export
  if (key == 's') {
    ofImage screenshot;
    screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
    screenshot.save("saved_"+ofGetTimestampString()+".png");
  }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
  length = ofRandom(100, 300);

}
