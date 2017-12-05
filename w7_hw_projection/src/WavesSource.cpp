#include "WavesSource.h"

// week 7 : projection
//
// Celine Chappert
//
// Generative drawing originally coded in Processing by Saskia.
// Found on openProcessing at :
// https://www.openprocessing.org/user/48307


void WavesSource::setup(){
    name = "Waves Source";
    rectColor = ofColor(255);
    allocate(ofGetWidth(), ofGetHeight());
}

void WavesSource::setName(string _name){
    name = _name;
}

void WavesSource::setColor(ofColor c){
    rectColor = c;
}

void WavesSource::update(){
}


void WavesSource::draw(){
    ofClear(0); //clear the buffer

    waves();

}

//--------------------------------------------------------------
void WavesSource::waves(){
    
    ofBackground(36,41,73);
    
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofScale(2.0, 2.0);
    
    frameCount = ofGetFrameNum();
    
    t = (float) frameCount/maxFrameCount;
    
    theta = TWO_PI*t;
    
    for ( int x= -175; x <= 175; x += 25) {
        for (int y= -100; y <= 155; y += 50) {
            float offSet = 50*x+y+y;
            float x2 = ofMap(cos(-theta+offSet), 0, 1, 0, 25);
            float y2 = ofMap(cos(-theta+offSet), 0, 1, 25, 0);
            float sz2 = ofMap(sin(-theta+offSet), 0, 1, 15, 45);
            
            ofSetColor(250-(x/2), 150+(x/6), 250-(y/2));
            
            ofDrawEllipse(x+x2, y-y2, sz2, sz2);
        }
    }
}
