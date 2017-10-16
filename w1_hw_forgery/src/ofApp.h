#pragma once

#include "ofMain.h"

#include "Stroke.h"

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
// Importing large chunks of the library probably wasn't
// necessary in some parts. 
//
// Sam Luford for helping me figure out how to calculate
// the coordinates of a point on an arc based.
//
// Comments below
//
//--------------------------------------------------------------

//---------------------------
// Below:
// start code snippet from
// ofxPathFitter addon
//
#define IDLE		0
#define DRAWING		1
#define EDITING		2
// end  ofxPathFitter snippet
//---------------------------

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		int width;
		int height;

		ofPath path;

		void keyPressed(int key);

		//---------------------------
		// Below:
		// start code snippet from
		// ofxPathFitter addon
		//
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);

		ofRectangle canvas;
		vector <Stroke> strokes;
		Stroke currentStroke;
		int iSelectedStroke;
		int iSelectedVertex;
		int selectedHandle;
		ofVec2f lastMousePos;
		bool isLeftMouseButtonPressed;
		bool isSavingSVG;
		bool isSavingRaster;
		string save_name;
		bool flushCanvas;
		int usrtask;
		int set_smoothness;
		// end  ofxPathFitter snippet
		//---------------------------
};
