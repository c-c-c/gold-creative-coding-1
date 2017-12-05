#pragma once

#include "ofMain.h"
#include "FboSource.h"

class WavesSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void drawMovingRect(int, int, int, int);
        void setName(string _name);
        void setColor(ofColor);
    
        ofColor rectColor;
    
        void waves();
    
        // Variables originally
        // created by Saskia.
        float t;
        float theta;
        int maxFrameCount = 200;
        int frameCount;
};
