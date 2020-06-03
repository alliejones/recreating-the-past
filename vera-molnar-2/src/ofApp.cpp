#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  fill1 = lineFill(8);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  fill1.draw(100, 100);
}

ofFbo ofApp::lineFill(int space) {
  ofFboSettings s;
  s.width = ofGetWidth();
  s.height = ofGetHeight();

  ofFbo fbo;
  fbo.allocate(s);
  fbo.begin();
    ofClear(255,255,255, 0);
    for (int i = 0; i < 100; i++) {
      ofLine(0, space * i, (int) fbo.getWidth(), space * i);
    }
  fbo.end();
  return fbo;
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
