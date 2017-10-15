#pragma once

#include "ofMain.h"

#include "Stroke.h"

// credits to addon example
#define IDLE		0
#define DRAWING		1
#define EDITING		2

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		int width;
		int height;

		ofPath path;

		void keyPressed(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);


		// credits to addon exampel

		// ui
		ofRectangle canvas;


		// line
		vector <Stroke> strokes;
		Stroke currentStroke;
		int iSelectedStroke;
		int iSelectedVertex;
		int selectedHandle;

		// state
		ofVec2f lastMousePos;
		bool isLeftMouseButtonPressed;
		bool isSavingSVG;
		bool isSavingRaster;
		string save_name;
		bool flushCanvas;
		int usrtask;

		// settings
		int set_smoothness;
};
