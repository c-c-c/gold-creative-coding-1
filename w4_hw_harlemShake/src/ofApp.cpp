#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // set bg to black
    
    ofBackground(0);
    
    // disables automatic bg clearing
    ofSetBackgroundAuto(false);
    
    // setting spacing and initial position of shapes
    
    spacingX = ofGetWidth()/numX;
    spacingY = ofGetHeight()/numY;
    
    startingX = spacingX/2;
    startingY = spacingY/2;
    
    // looping over the values of the array
    
    for (int i = 0; i<numX; i++) {
        for (int j = 0; j<numY; j++) {
            noiseSeeds[i][j] = ofRandom(1000);
        }
    }
    
    // initial position is immobile
    
    goCrazy = false;
    
    stepSize = 20;
    
    noise = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i<numX; i++) {
        for (int j = 0; j<numY; j++) {
            noiseSeeds[i][j] += 0.02;
        }
    }
    
    if (goCrazy==true) {
        if (noise < 20) {
            noise +=1;
        }
    }
    
    if (goCrazy == false) {
        if (noise > 0) {
            noise -=1;
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
        // black rect covers the whole screen but
        // has alpha of 20 to leave shape trail visible
    
        ofSetColor(0, 20);
        ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
        
        ofSetColor(255, 255);
        
        for (int i = 0; i<numX; i++) {
            for (int j = 0; j<numY; j++) {
                
                int locX = i*spacingX+stepSize;
                int locY = j*spacingY+stepSize;
                
                if (i==20 && j==20) {
                    locX = locX + ofSignedNoise(noiseSeeds[i][j])*stepSize;
                    locY = locY + ofSignedNoise(noiseSeeds[i][j]+500)*stepSize;
                }
                
                else {
                    locX = locX + ofSignedNoise(noiseSeeds[i][j])*noise;
                    locY = locY + ofSignedNoise(noiseSeeds[i][j]+500)*noise;
                }
                
                ofDrawEllipse(locX, locY, 3,3);
            }
        }
        
        
    }

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    // toggle for the shake
    goCrazy = !goCrazy;

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
