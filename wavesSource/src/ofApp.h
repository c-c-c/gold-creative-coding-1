#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
        void waves();
    
        float t;
        float theta;
        int maxFrameCount = 200;
    
        int frameCount;
		
};
