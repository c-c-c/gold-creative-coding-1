#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		static const int numX=25;
		static const int numY=25;
    
		// arrays are simpler than vectors
		// because they are not elastic in size
    
		float noiseSeeds[numX][numY];

		float spacingX;
		float spacingY;

		float startingX;
		float startingY;

		bool goCrazy;

		float stepSize;

        float noise;
};
