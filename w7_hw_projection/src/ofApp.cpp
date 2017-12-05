#include "ofApp.h"

void ofApp::setup(){
    ofBackground(0);
    
    // Enable or disable audio for video sources globally
    // Set this to false to save resources on the Raspberry Pi
    ofx::piMapper::VideoSource::enableAudio = true;
    ofx::piMapper::VideoSource::useHDMIForAudio = false;
    
    // Add our CustomSource to list of fbo sources of the piMapper
    // FBO sources should be added before piMapper.setup() so the
    // piMapper is able to load the source if it is assigned to
    // a surface in XML settings.
    // 1
    movingRectSource1 = new MovingRectSource();
    piMapper.registerFboSource(movingRectSource1);
    movingRectSource1->setColor(ofColor(255,0,0)); //call the functions to differentiate the buffer, after "registering it"
    movingRectSource1->setName("red moving rect");
    
    // source
    movingRectSource2 = new MovingRectSource();
    piMapper.registerFboSource(movingRectSource2);
    movingRectSource2->setColor(ofColor(0,255,0));
    movingRectSource2->setName("green moving rect");
    
    // waves
    wavesSource = new WavesSource();
    piMapper.registerFboSource(wavesSource);

    
    // custom source
    customSource = new CustomSource();
    piMapper.registerFboSource(customSource);
    
    piMapper.setup();
    
    // The info layer is hidden by default, press <i> to toggle
    // piMapper.showInfo();
    
    ofSetFullscreen(Settings::instance()->getFullscreen());
    ofSetEscapeQuitsApp(false);
    
    dummyObjects.load("star.png");
}

void ofApp::update(){
    piMapper.update();
}

void ofApp::draw(){
    dummyObjects.draw(600, 225);
    piMapper.draw();
}

void ofApp::keyPressed(int key){
    piMapper.keyPressed(key);
}

void ofApp::keyReleased(int key){
    piMapper.keyReleased(key);
}

void ofApp::mousePressed(int x, int y, int button){
    piMapper.mousePressed(x, y, button);
}

void ofApp::mouseReleased(int x, int y, int button){
    piMapper.mouseReleased(x, y, button);
}

void ofApp::mouseDragged(int x, int y, int button){
    piMapper.mouseDragged(x, y, button);
}
