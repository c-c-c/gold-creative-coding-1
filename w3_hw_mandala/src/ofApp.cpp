#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofHideCursor();
    ofBackground(0);

    angleStep = 0.1;
    rotAngle = 0;

}

//--------------------------------------------------------------
void ofApp::update(){

  if (rotAngle > 15 || rotAngle < -15) {
    angleStep == angleStep * -1;
  }

  rotAngle = rotAngle + angleStep;

}

//--------------------------------------------------------------
void ofApp::draw(){

  // shape 1

  int resolution = ofMap(ofGetMouseX(), 0, ofGetWidth(), 3, 20, true);
  int radius1 = 200;
  int radius2 = ofMap(ofGetMouseY(), 0, ofGetHeight(), 50, 400, true);

  float noOfStars = 20;

  // create 20 stars
  for (float i = 0; i < noOfStars; i++) {

    ofPushMatrix();

    int color = ofMap(i, 0, noOfStars, 0, 255, true);
    ofSetColor(color, noOfStars);

    ofFill();

    ofTranslate(ofGetWidth()/2,ofGetHeight()/2);

    ofRotate(i*rotAngle);

    // ofScale(1/i*20, 1/i*20);

    ofScale((noOfStars+i)/noOfStars, (noOfStars+i)/noOfStars);

    star(0, 0, radius1, radius2, resolution);

    ofPopMatrix();
  }



}

//--------------------------------------------------------------
void ofApp::star(float x, float y, float radius1, float radius2, int npoints) {


  float angle = 360.0 / npoints;
  float halfAngle = angle/2.0;

  ofSetPolyMode(OF_POLY_WINDING_NONZERO);
  ofBeginShape();
  for (float a = 0; a < 360.0; a += angle)
  {
  float sx = x + cos(ofDegToRad(a)) * radius2;
  float sy = y + sin(ofDegToRad(a)) * radius2;
  ofVertex(sx, sy);
  sx = x + cos(ofDegToRad(a+halfAngle)) * radius1;
  sy = y + sin(ofDegToRad(a+halfAngle)) * radius1;
  ofVertex(sx, sy);
  }



  ofEndShape();


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  switch (key){

      // export
      case 's':
          ofImage screenshot;
          screenshot.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
          screenshot.save("saved_"+ofGetTimestampString()+".png");
          cout << "screenshot saved" << endl;
          break;
      // case 'z':
      //     speedOfRotation -= 0.05f;
      //     break;
      // case 's':
      //     rotateAmount.x += 0.05f;
      //     break;
      // case 'x':
      //      rotateAmount.x -= 0.05f;
      //     break;
      // case 'd':
      //     rotateAmount.y += 0.05f;
      //     break;
      // case 'c':
      //      rotateAmount.y -= 0.05f;
      //     break;
      // case 'f':
      //     rotateAmount.z += 0.05f;
      //     break;
      // case 'v':
      //      rotateAmount.z -= 0.05f;
      //     break;
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
