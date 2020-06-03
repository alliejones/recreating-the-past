#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {}

//--------------------------------------------------------------
void ofApp::update() {}

//--------------------------------------------------------------
void ofApp::draw() {

  int pointCount = 30;

  vector<glm::vec3> smallOval = getSmallOvalPoints(pointCount);
  vector<glm::vec3> largeOval = getLargeOvalPoints(pointCount);

  ofSetBackgroundColor(0);
  ofSetColor(255);
  int index = 0;
  for (auto point1 : smallOval) {
    auto point2 = largeOval[index];
    ofDrawLine(point1.x, point1.y, point2.x, point2.y);
    index++;
  }
}

vector<glm::vec3> ofApp::getSmallOvalPoints(int pointCount) {
  int totalSteps = 50;
  float currentStep = fmod(ofGetElapsedTimef(), totalSteps);
  float ovalRadius = 100;
  float overallScale = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0.5, 1.25);
  float yScale = 1.4;
  float angle = ofMap(currentStep, 0., totalSteps, 0., M_TWO_PI);

  float xorig = ofGetWidth() / 2;
  float yorig = ofGetHeight() / 2;
  float radius = ofGetHeight() / 2 - 100;

  float ovalX = xorig + radius * cos(angle);
  float ovalY = yorig + radius * sin(angle);

  ofPolyline oval;
  for (int i = 0; i < pointCount; i++) {
    float innerAngle = ofMap(i, 0, pointCount, 0, M_PI);
    float x = ovalRadius * overallScale * cos(innerAngle);
    float y = ovalRadius * overallScale * yScale * sin(innerAngle);
    float xr = x * cos(angle) - y * sin(angle);
    float yr = y * cos(angle) + x * sin(angle);
    oval.addVertex(xr, yr);
  }
  oval.translate(glm::vec2(ovalX, ovalY));

  return oval.getVertices();
}

vector<glm::vec3> ofApp::getLargeOvalPoints(int pointCount) {
  int totalSteps = 55;
  float currentStep = fmod(ofGetElapsedTimef(), totalSteps);
  float ovalRadius = 200;
  float overallScale = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0.9, 1.25);
  float yScale = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0.9, 1.2);
  float angle = ofMap(currentStep, 0., totalSteps, 0., M_TWO_PI);

  float xorig = ofGetWidth() / 2;
  float yorig = ofGetHeight() / 2;
  float radius = 25;

  float ovalX = xorig + radius * cos(angle);
  float ovalY = yorig + radius * sin(angle);

  ofPolyline oval;
  for (int i = 0; i < pointCount; i++) {
    float innerAngle = ofMap(i, 0, pointCount, 0, M_PI);
    float x = ovalRadius * overallScale * cos(innerAngle);
    float y = ovalRadius * overallScale * yScale * sin(innerAngle);
    float xr = x * cos(angle) - y * sin(angle);
    float yr = y * cos(angle) + x * sin(angle);
    oval.addVertex(xr, yr);
  }
  oval.translate(glm::vec2(ovalX, ovalY));

  return oval.getVertices();
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
