#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "MovingRectSource.h"
#include "CustomSource.h"
#include "VideoSource.h"
#include "WavesSource.h"

class ofApp : public ofBaseApp {
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    
    ofxPiMapper piMapper;

    MovingRectSource * movingRectSource1;
    MovingRectSource * movingRectSource2;
    CustomSource * customSource;
    WavesSource * wavesSource;
    ofImage dummyObjects;
};
