#include "ofApp.h"

//--------------------------------------------------------------
// Special thanks to Sam Luford for the trig help for the lines :)
//
//
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

  // grid system
  for (int x = 0 ; x < width ; x+=10) {
    ofSetColor(220);
    ofDrawLine(x, 0, x, height);

    for (int y = 0; y < height ; y+=10 ) {
      ofSetColor(220);
      ofDrawLine(0, y, width, y);
    }
  }

  // centering and translating the coordinate system
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

    // top left line

    // radiuses
    int rSmall;
    int rMedium;
    int rBig;

    // points
    int p1x;
    int p1y;
    int p2x;
    int p2y;

    rSmall = 200;
    rMedium = 250;
    rBig = 300;

    p1x = rBig * cos((PI/2) - (PI/3));
    p1y = rBig * sin((PI/2) - (PI/3));

    ofPoint point1(-p1x, -p1y);

    p2x = rSmall * cos((PI/2) - (PI/3));
    p2y = rSmall * sin((PI/2) - (PI/3));

    ofPoint point2(-p2x, -p2y);

    ofDrawLine(point1, point2);

    // bottom left line

    int p3x;
    int p3y;
    int p4x;
    int p4y;

    p3x = rBig * cos((PI/3) - (PI/2));
    p3y = rBig * sin((PI/3) - (PI/2));

    ofPoint point3(-p3x, -p3y);

    p4x = rSmall * cos((PI/3) - (PI/2));
    p4y = rSmall * sin((PI/3) - (PI/2));

    ofPoint point4(-p4x, -p4y);

    ofDrawLine(point3, point4);

    // top right line

    int p5x;
    int p5y;
    int p6x;
    int p6y;

    p5x = rMedium * cos((PI/4) - (PI/2));
    p5y = rMedium * sin((PI/4) - (PI/2));

    ofPoint point5(p5x, p5y);

    p6x = rSmall * cos((PI/4) - (PI/2));
    p6y = rSmall * sin((PI/4) - (PI/2));

    ofPoint point6(p6x, p6y);

    ofDrawLine(point5, point6);

    // bottom right line WTFWTFWTF

    int p11x;
    int p11y;
    int p12x;
    int p12y;

    p11x = rMedium * cos((PI/4) - (PI/2));
    p11y = rMedium * sin((PI/4) - (PI/2));

    ofPoint point5(p5x, p5y);

    p12x = rSmall * cos((PI/4) - (PI/2));
    p12y = rSmall * sin((PI/4) - (PI/2));

    ofPoint point6(p6x, p6y);

    ofDrawLine(point5, point6);


  ofPopMatrix();

  // top and bottom line lines
  ofDrawLine(400, 100, 400, 200);
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

  // curved lines
  ofPolyline curvedPolyline;

    // test
    curvedPolyline.curveTo(350, 100);  // These curves are Catmull-Rom splines
    curvedPolyline.curveTo(350, 100);  // Necessary Duplicate for Control Point
    curvedPolyline.curveTo(400, 150);
    curvedPolyline.curveTo(450, 100);
    curvedPolyline.curveTo(500, 150);
    curvedPolyline.curveTo(550, 100);
    curvedPolyline.curveTo(550, 100);

  curvedPolyline.curveTo(550, 100);
  curvedPolyline.curveTo(width/2, 200);

  ofSetLineWidth(2.0);  // Line widths apply to polylines
  ofSetColor(255,100,0);
  curvedPolyline.draw();  // Nice and easy, right?

  // grids


  // ofSetColor(0, 255, 255);
  // ofSetLineWidth(0.5);
  // ofDrawLine(width/2, 0, width/2, height); // vertical
  // ofDrawLine(0, height/2, width, height/2); // horizontal

  // test
  // ofSetColor(255, 0, 0);
  // ofDrawLine(width/2, 200, width/2, 600);



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
