#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
  //  gui.setup();
  //  gui.add(lineOffset.set("lineOffset", 10, 1, 100));
  randSeed = ofRandom(10000);
  ofBackground(255);
  ofSetColor(0);
  ofEnableAntiAliasing();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
  ofSeedRandom(randSeed);

  vector<int> lineOffsets { 4, 8, 16, 32, 64, 128 };

  int cellSize = 50;

  for (int x = 0; x <= ofGetWindowWidth(); x += cellSize) {
    for (int y = 0; y <= ofGetWindowHeight(); y += cellSize*2) {
      ofPushMatrix();
      ofTranslate(x, y);
      if (ofRandom(1.0) < 0.5) {
        drawRect(cellSize*2, cellSize, lineOffsets[ofRandom(lineOffsets.size())]);
      } else {
        drawRect(cellSize, cellSize*2,  lineOffsets[ofRandom(lineOffsets.size())]);
      }
      ofPopMatrix();
    }
  }

  // gui.draw();
}

void ofApp::drawRect(int width, int height, int lineOffset) {
  int xm, ym;
  if (width > height) {
    xm = 2;
    ym = 1;
  } else {
    xm = 1;
    ym = 2;
  }

  // start at the diagonal and then draw lines outwards in both directions
  for (int pos = 0; pos < std::min(width, height); pos += lineOffset) {
    ofLine(pos * xm, 0, width, height - pos*ym);
    ofLine(0, pos * ym, width - pos*xm, height);
  }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
  randSeed = ofRandom(10000);
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
