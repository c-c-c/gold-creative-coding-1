#include "MovingRectSource.h"

void MovingRectSource::setup(){
	// Give our source a decent name
    name = "Moving Rect FBO Source";
    rectColor = ofColor(255);
	// Allocate our FBO source, decide how big it should be
    allocate(500, 500);
}

void MovingRectSource::setName(string _name){
    name = _name;
}

void MovingRectSource::setColor(ofColor c){
    rectColor = c;
}

// Don't do any drawing here
void MovingRectSource::update(){
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void MovingRectSource::draw(){
    ofClear(0); //clear the buffer

    //do it with static values
    //since the buffer is 500x500, then...
    //drawMovingRect(250, 250, 500, 500);

    //or pass it dynamic values (ie. ask the fbo how big it is)
    drawMovingRect(fbo->getWidth()/2, fbo->getHeight()/2, fbo->getWidth(), fbo->getHeight());
    
    drawTunnel(ofGetFrameNum()*3, 0,0,500,500,ofColor(200,0,0), ofColor(0,0,100));
}

void MovingRectSource::drawMovingRect(int x, int y, int w, int h){
    ofPushMatrix();
    ofPushStyle();
    ofSetColor(rectColor);
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofTranslate(x,y);
    float phase = sin(ofDegToRad(ofGetFrameNum()*2));
    float s = ofMap(phase, -1, 1, 0.2, 1);
    ofScale(s,s,1);
    ofDrawRectangle(0,0,w,h);
    ofPopStyle();
    ofPopMatrix();
}

//--------------------------------------------------------------
void MovingRectSource::drawTunnel(float phase, int locX, int locY, int width, int height, ofColor c1, ofColor c2){
    ofPushMatrix();
    ofPushStyle();
    ofTranslate(locX + width/2, locY + height/2);
    int totalSquares = 10;
    float maxDiff = width/totalSquares;
    float squareSpacingX = width/totalSquares;
    float squareSpacingY = height/totalSquares;
    
    for (int i = totalSquares; i>0; i--) {
        float tempPhase = phase + (i * 360/totalSquares);
        drawSquare(tempPhase, i * squareSpacingX, i * squareSpacingY, maxDiff, c1, c2);
    }
    ofPopMatrix();
    ofPopStyle();
}

//--------------------------------------------------------------
void MovingRectSource::drawSquare(float phase, float width, float height, float maxDiff, ofColor c1, ofColor c2){
    ofPushStyle();
    ofPushMatrix();
    ofSetRectMode(OF_RECTMODE_CENTER);
    ofSetColor(c1);
    ofDrawRectangle(0,0,width,height);
    ofSetColor(c2);
    float sizeDiff = maxDiff * (sin(ofDegToRad(phase))+1)/2 - 2;
    ofDrawRectangle(0,0,width-sizeDiff, height-sizeDiff);
    ofPopMatrix();
    ofPopStyle();
}
