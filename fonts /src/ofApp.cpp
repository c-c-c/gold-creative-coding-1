#include "ofApp.h"


//--------------------------------------------------------------

// Celine Chappert
// 26 November 2017
// Assignment week 6 : Reverse Engineering

// Reverse engineering the video of the horse with lines being
// drawn instead of pixels.
//
// Here we are analyze webcam pixels,
// where lines are being drawn to represent the subject of the webcam feed.
//
// To make this more interesting (less black&white) and make use of more
// data, I thought it could be interesting to play with pixel color data.
// I found help and code snippets which I will reference from a personal
// blog online.
// Link : https://sites.google.com/site/ofauckland/examples/11-hsb-color-vector-flow-field

//--------------------------------------------------------------

//--------------------------------------------------------------
void ofApp::setup(){
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    video.initGrabber(width,height,true);
}

//--------------------------------------------------------------
void ofApp::update(){

    video.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    ofBackground(0);
    
    ofSetColor(0);
    
    // for every x and y pixel in the screen :
    for (int y=0; y<height; y+=10) {
        for (int x=0; x<width; x+=10) {
            
            // get pixel color
            int color = (y*width+x)*3;
            // get red, green and blue channel
            int r = video.getPixels()[color+0];
            int g = video.getPixels()[color+1];
            int b = video.getPixels()[color+2];
            
            //maximum brightness per channel is 255 so 255*3
            maxRGB = 765.0;
            
            //calculate brightness
            float brightness = (r+b+g) / maxRGB;

            //use HSB color
            
            // code below from the link.
//            ofSetColor(ofColor::fromHsb(brightness*255,255,255));
            
            //calculate sine and cosine of brightness
            // Code written not by me !
            // Code snippet found on the link below and copy/pasted.
            float co = cos(brightness*TWO_PI);
            float si = sin(brightness*TWO_PI);
            
            //draw rotated line based on brightness
            ofSetLineWidth(2.0);
            
            ofDrawLine(x-8*co, y-8*si, x+8*co, y+8*si);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key == 's') {
        ofImage saved;
        saved.grabScreen(0, 0, width, height);
        saved.save("save"+ofGetTimestampString()+".png");    }

}

