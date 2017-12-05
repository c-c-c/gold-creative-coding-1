#pragma once

#include "ofMain.h"
#include "FboSource.h"

class MovingRectSource : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void drawMovingRect(int, int, int, int);
        void setName(string _name);
        void setColor(ofColor);
        ofColor rectColor;
    
    void drawTunnel(float phase, int locX, int locY, int width, int height, ofColor c1, ofColor c2);
    void drawSquare(float phase, float width, float height, float maxDiff, ofColor c1, ofColor c2);
};
