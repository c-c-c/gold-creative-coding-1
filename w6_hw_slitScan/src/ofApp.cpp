#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    camWidth 		= 480;
    camHeight 		= 360;
    slitScanWidth   = 1000; //width of the slit scan image
    slitScanGrabColumn = 240; //grab pixels with x=240 (i.e. the center column of the webcam image)
    
    //print the list of available webcams to the console
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        cout << devices[i].id << ": " << devices[i].deviceName;
        if( devices[i].bAvailable ){
            cout << endl;
        }else{
            cout << " - unavailable " << endl;
        }
    }
    
    vidGrabber.setDeviceID(0); //choose the index from the list of webcams that was printed to the console
    vidGrabber.setUseTexture(true);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth,camHeight);
    
    slitScanImage.allocate(slitScanWidth, camHeight, OF_IMAGE_COLOR);
    ofSetVerticalSync(true);
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    vidGrabber.update();
    
    if (vidGrabber.isFrameNew()){
        unsigned char * videoPixels = vidGrabber.getPixels();
        unsigned char * imagePixels = slitScanImage.getPixels();
        
        movePixelsInImage(&slitScanImage);
        
        for (int y = 0; y < camHeight; y++) {
            int imagePosition = y*(slitScanWidth*3)+(slitScanWidth-1)*3;
            int videoPosition = y*(camWidth*3)+slitScanGrabColumn*3;
            imagePixels[imagePosition]   = videoPixels[videoPosition];
            imagePixels[imagePosition+1] = videoPixels[videoPosition+1];
            imagePixels[imagePosition+2] = videoPixels[videoPosition+2];
        }
        
        slitScanImage.update();
        nrFrames++;
        
        if (nrFrames % slitScanWidth == 0) {
            slitScanImage.saveImage("slitscan"
                                    + ofToString(ofGetUnixTime())
                                    + ".png",OF_IMAGE_QUALITY_BEST);
        }
    }
    
}

//move all pixels one column to the left
void ofApp::movePixelsInImage(ofImage * image) {
    unsigned char * pixels = image->getPixels(); //equivalent to (*image).getPixels();
    for (int x=0; x<image->width-1; x++) {
        for (int y=0; y<image->height; y++) {
            int position = y*(image->width*3)+x*3;
            int nextPosition = position+3;
            pixels[position] = pixels[nextPosition];
            pixels[position+1] = pixels[nextPosition+1];
            pixels[position+2] = pixels[nextPosition+2];
        }
    }
    image->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);
    vidGrabber.draw(20,20);
    slitScanImage.draw(20, camHeight+40);
    ofLine(20+slitScanGrabColumn,20,20+slitScanGrabColumn,20+camHeight);
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
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
