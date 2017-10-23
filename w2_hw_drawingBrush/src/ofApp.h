#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void drawMode1();
		void drawMode2();
		void drawMode3();

		void keyPressed(int key);
		void mousePressed(int x, int y, int button);

		bool showGrid;

		bool mode1;
		bool mode2;
		bool mode3;

		float stepSize;

		float length;
		float angle;
		float angleSpeed;

		int radius;





};
