#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    gui.setup();
    
    gui.add(squareOneJitter.set("squareOneJitter", 15, 0, 50));
    gui.add(squareOneMargin.set("squareOneMargin", 10, 0, 50));
    gui.add(squareOneWidth.set("squareOneWidth", 72, 0, 100));
    gui.add(squareOneDropoff.set("squareOneDropoff", 0.85, 0.0, 1.0));
    
    gui.add(squareTwoJitter.set("squareTwoJitter", 10, 0, 50));
    gui.add(squareTwoMargin.set("squareTwoMargin", 33, 0, 50));
    gui.add(squareTwoWidth.set("squareTwoWidth", 34, 0, 100));
    gui.add(squareTwoDropoff.set("squareTwoDropoff", 0.85, 0.0, 1.0));
    
    showGUI = true;
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(mouseX / 10 * 1000);
    
    ofBackground(255);
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(3);


    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            ofPushMatrix();
            int xOffset = 50 + (i*100);
            int yOffset = 50 + (j*100);
            ofTranslate(xOffset, yOffset);
            
            if (ofRandom(1) < squareOneDropoff) {
                randomQuad(squareOneWidth, squareOneJitter, squareOneMargin);
            }
            
            if (ofRandom(1) < squareTwoDropoff) {
                randomQuad(squareTwoWidth, squareTwoJitter, squareTwoMargin);
            }

            ofPopMatrix();
        }
    }
    
    if (showGUI) {
        gui.draw();
    }
}

void ofApp::randomQuad(int width, int jitter, int margin) {
    ofBeginShape();
    randomVertex(margin, margin, jitter);
    randomVertex(margin + width, margin, jitter);
    randomVertex(margin + width, margin + width, jitter);
    randomVertex(margin, margin + width, jitter);
    ofEndShape(true);
}

void ofApp::randomVertex(int x, int y, int jitter) {
    int x_ = ofRandom(x - jitter, x + jitter);
    int y_ = ofRandom(y - jitter, y + jitter);
    ofVertex(x_, y_);
    
    ofFill();
    ofDrawCircle(x_, y_, 1);
    ofNoFill();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    int SPACE_KEY = 32;
    if (key == SPACE_KEY) {
        showGUI = !showGUI;
    }
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
