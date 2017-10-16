#include "ofApp.h"

//--------------------------------------------------------------
// Celine Chappert
// 16 October 2017
// Assignment week 1 : Forgery
//
// All code my own EXCEPT when explicitely noted below
//
// Special credits to :
// ofxPathFitter addon for the drawing tool which I used to
// build the thicker curves on each side of the circle.
//
// Sam Luford for helping me figure out how to calculate
// the coordinates of a point on an arc based.
//
// Comments below
//
//--------------------------------------------------------------


void ofApp::setup(){

  ofSetBackgroundAuto(false);
	ofBackground(255);
  ofSetCircleResolution(200);
	ofSetFrameRate(60);


  //---------------------------
  // Below:
  // start code snippet from
  // ofxPathFitter addon
  //
	canvas = ofRectangle(0, 0, 500, 500);
	lastMousePos = ofVec2f(0,0);
	isLeftMouseButtonPressed = false;
	isSavingSVG = false;
	isSavingRaster = false;
	usrtask = DRAWING;
	iSelectedStroke = -1;
	iSelectedVertex = -1;
	set_smoothness = 5;
  // end  ofxPathFitter snippet
  //---------------------------

  width = ofGetWidth();
  height = ofGetHeight();

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

  //---------------------------
  // Below:
  // start ofxPathFitter snippet
  //
  if (flushCanvas || isLeftMouseButtonPressed) {
  		flushCanvas = false;
      ofBackground(255);
      ofSetColor(0);
  		for (int i = 0; i<strokes.size(); i++) {
  			strokes[i].draw();
  		}

  		// active stroke
  		currentStroke.drawActive(set_smoothness);

  		if (isSavingSVG) {
  			isSavingSVG = false;
  			ofEndSaveScreenAsSVG();
  		}
  		else if (isSavingRaster) {
  			isSavingRaster = false;
  			ofImage savedImg;
  			glReadBuffer(GL_FRONT);
  			savedImg.grabScreen(canvas.x, canvas.y, canvas.width, canvas.height);
  			savedImg.save(save_name);
  			savedImg.clear();
  		}

  		if (usrtask == EDITING && iSelectedStroke != -1) {
  			strokes[iSelectedStroke].drawEditable(iSelectedVertex);
  		}
  	}
    // end  ofxPathFitter snippet
    //---------------------------


  // centering and translating the coordinate system
  ofPushMatrix();
  ofTranslate(width/2, height/2);

  //---------------------------
  // CIRCLES
  //---------------------------

    // Smaller circle: rSmall
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(1.0);
    ofDrawCircle(0, 0, 200);

    // Medium circle: rMedium
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(1.0);
    ofDrawCircle(0, 0, 250);

    // radiuses
    int rSmall;
    int rMedium;
    int rBig;

//---------------------------
// DIAGONALS
//---------------------------

    // points
    int p1x;
    int p1y;
    int p2x;
    int p2y;

    rSmall = 200;
    rMedium = 250;
    rBig = 300;

    // The formula below was given to me
    // by Sam Luford.
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

// RIGHT

    // top right line

    int p5x;
    int p5y;
    int p6x;
    int p6y;

    p5x = rMedium * cos((PI/2) - (PI/5));
    p5y = rMedium * sin((PI/2) - (PI/5));

    ofPoint point5(p5x, -p5y);

    p6x = rSmall * cos((PI/2) - (PI/5));
    p6y = rSmall * sin((PI/2) - (PI/5));

    ofPoint point6(p6x, -p6y);

    ofDrawLine(point5, point6);

    // top right line 2nd: TEST

    int p7x;
    int p7y;
    int p8x;
    int p8y;

    p7x = rMedium * cos((PI/2) - ((PI/5) + (PI/5)));
    p7y = rMedium * sin((PI/2) - ((PI/5) + (PI/5)));

    ofPoint point7(p7x, p7y);

    p8x = rSmall * cos((PI/2) - ((PI/5) + (PI/5)));
    p8y = rSmall * sin((PI/2) - ((PI/5) + (PI/5)));

    ofPoint point8(p8x, p8y);

    ofDrawLine(point7, point8);

    // bottom right line 2nd

    int p9x;
    int p9y;
    int p10x;
    int p10y;

    p9x = rMedium * cos((PI/2) - ((PI/5) + (PI/5)));
    p9y = rMedium * sin((PI/2) - ((PI/5) + (PI/5)));

    ofPoint point9(p9x, -p9y);

    p10x = rSmall * cos((PI/2) - ((PI/5) + (PI/5)));
    p10y = rSmall * sin((PI/2) - ((PI/5) + (PI/5)));

    ofPoint point10(p10x, -p10y);

    ofDrawLine(point9, point10);


    // bottom right line

    int p11x;
    int p11y;
    int p12x;
    int p12y;

    p11x = rMedium * cos((PI/2) - (PI/5));
    p11y = rMedium * sin(-(PI/2) - (PI/5));

    ofPoint point11(p11x, -p11y);

    p12x = rSmall * cos((PI/2) - (PI/5));
    p12y = rSmall * sin(-(PI/2) - (PI/5));

    ofPoint point12(p12x, -p12y);

    ofDrawLine(point11, point12);

  ofPopMatrix();

  // Now we are out of the centered coordinate system

  // building top and bottom line lines
  ofSetLineWidth(1.0);
  ofDrawLine(400, 100, 400, 200);
  ofSetLineWidth(1.0);
  ofDrawLine(400, 600, 400, 700);

  //---------------------------
  // ARCS
  //---------------------------

  // half-circle on the right
  ofPolyline polyline1;
    ofSetLineWidth(1.0);
    ofPoint arcRight(400,400);
    polyline1.arc(arcRight,225,225,-90, 90, 200);
    polyline1.draw();

  // half-circle on the left
  ofPolyline polyline2;
    ofSetLineWidth(1.0);
    ofPoint arcLeft(400,400);
    polyline2.arc(arcLeft,300,300, 90, 270, 200);
    polyline2.draw();


    //---------------------------
    // CURVE LINES
    //
    // This is my original method for drawing the curves.
    // It works, which is why I want to keep the code for future reference.
    // I am using the curveTo() method on the ofPolyline object.
    // The method consists of calculating points on the arc and
    // add them as vertexes on a curved segment.
    // However, this is repetitive and there had to be another way.
    // Hence the ofxPathFitter library.
    //---------------------------

  // ofPolyline curvedPolyline, curvedPolyline2;
  //
  // // ofPoint v0(400, 175);
  // int v1x;
  // int v1y;
  // ofPoint v1(v1x, -v1y);
  // v1x = rSmall * cos((PI/2) - (PI/10));
  // v1y = rSmall * sin((PI/2) - (PI/10));
  //
  // ofPoint v0(400, 200);
  // // ofPoint v1(463, 210);
  // ofPoint v2(533, 218);
  // ofPoint v3(600, 250);
  // ofPoint v4(615, 330);
  // ofPoint v5(600, 400);
  // ofPoint v6(615, 470);
  // ofPoint v7(600, 550);
  // ofPoint v8(533, 583);
  // ofPoint v9(463, 590);
  // ofPoint v10(400, 625);
  //
  //   curvedPolyline.curveTo(v0);
  //   curvedPolyline.curveTo(v0);
  //   curvedPolyline.curveTo(v1);
  //   curvedPolyline.curveTo(v2);
  //   curvedPolyline.curveTo(v3);
  //   curvedPolyline.curveTo(v5);
  //   curvedPolyline.curveTo(v6);
  //   curvedPolyline.curveTo(v7);
  //   curvedPolyline.curveTo(v8);
  //   curvedPolyline.curveTo(v9);
  //   curvedPolyline.curveTo(v10);
  //   curvedPolyline.curveTo(v10);
  //
  ofSetLineWidth(3.0);
  // ofSetColor(0);
  // curvedPolyline.getResampledBySpacing(1);
  // curvedPolyline.getSmoothed(3);
  // curvedPolyline.draw();

  // LEFT
  // ofPoint p0(400, 150);
  // ofPoint p1(300, 225);
  // ofPoint p2(185, 275);
  // ofPoint p3(100, 400);
  // ofPoint p4(185, 525);
  // ofPoint p5(300, 570);
  // ofPoint p6(400, 650);
  //
  //   curvedPolyline2.curveTo(p0);
  //   curvedPolyline2.curveTo(p0);
  //   curvedPolyline2.curveTo(p1);
  //   curvedPolyline2.curveTo(p2);
  //   curvedPolyline2.curveTo(p3);
  //   curvedPolyline2.curveTo(p4);
  //   curvedPolyline2.curveTo(p5);
  //   curvedPolyline2.curveTo(p6);
  //   curvedPolyline2.curveTo(p6);
  //
  // ofSetLineWidth(3.0);
  // ofSetColor(0);
  // curvedPolyline2.draw();



  // cout << "mouse x :" << ofGetMouseX() << endl;
  // cout << "mouse y :" << ofGetMouseY() << endl;


}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  if (key == 'c') {
    ofImage saved;
    saved.grabScreen(0, 0, width, height);
    saved.save("save"+ofGetTimestampString()+".png");
  }

  if (key == 'x') {
		isSavingRaster = true;
		save_name = "savedScreenshot.png";
	}
	else if (key == 's') {
		save_name = "savedScreenshot_" + ofGetTimestampString() + ".svg";
		ofBeginSaveScreenAsSVG(save_name, false, false, canvas);
		isSavingSVG = true;
	}
  //---------------------------
  // Below:
  // start code snippet from
  // ofxPathFitter addon
  //
	else if (key == 'd') {
		iSelectedStroke = -1;
		iSelectedVertex = -1;
		usrtask = DRAWING;
	}
	else if (key == 'e') {
		usrtask = EDITING;
	}
	flushCanvas = true;
}


//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (usrtask == EDITING && iSelectedStroke != -1) {

	}
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	ofVec2f mousePos(x, y);
	if (button == OF_MOUSE_BUTTON_LEFT) {
		if (usrtask == DRAWING) {
			currentStroke.addVertex(mousePos);
		}
		else if (usrtask == EDITING && iSelectedStroke != -1) {
			if (iSelectedVertex != -1) {
				if (selectedHandle == POINT) {
					strokes[iSelectedStroke].modifyVertex(iSelectedVertex, x, y);
				}
				else {
					strokes[iSelectedStroke].modifyHandle(iSelectedVertex, selectedHandle, x, y);
				}
			}
			else if (iSelectedStroke != -1 && mousePos.distance(lastMousePos)>1) {
				strokes[iSelectedStroke].translateLine(lastMousePos, x, y);
			}
		}
	}
	lastMousePos = mousePos;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	ofPoint mousePos(x, y);
	if (button == OF_MOUSE_BUTTON_LEFT) {
		isLeftMouseButtonPressed = true;

		if (usrtask == DRAWING) {
			currentStroke.startStroke();
		}
		else if (usrtask == EDITING) {
			if (iSelectedStroke != -1) {
				iSelectedVertex = strokes[iSelectedStroke].getSelectedVertex(iSelectedVertex, selectedHandle, x, y);
			}
			if (iSelectedVertex == -1) {
				iSelectedStroke = Stroke::getSelectedStroke(&strokes, mousePos);
			}
		}
	}
	lastMousePos = mousePos;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT) {
		isLeftMouseButtonPressed = false;

		if (usrtask == DRAWING) {
			if (currentStroke.line.size() > 1) {
				currentStroke.finishStroke(set_smoothness);
				strokes.push_back(currentStroke);
			}
			currentStroke.clear();  // Erase the vertices, allows us to start a new brush stroke
		}
	}

}
// end  ofxPathFitter snippet
//---------------------------
