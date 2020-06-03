#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  // gui.setup();
  // gui.add(angle.set("angle", 0., 0., M_PI * 2));
}
//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {
  cout << ofGetElapsedTimef() << endl;
  float xorig = 400;
  float yorig = 400;
  float radius = 300;
  angle = ofDegToRad(ofGetElapsedTimef() * 2);
  int pointCount = 120;
  for (int i = 0; i < pointCount; i++) {
    float x = xorig + cos(angle * i) * ((i / (float)pointCount) * radius);
    float y = yorig + sin(angle * i) * ((i / (float)pointCount) * radius);
    ofDrawCircle(x, y, 2);
  }
  // gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
