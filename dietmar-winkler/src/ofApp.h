#pragma once

#include "ofMain.h"
#include "ofxClipper.h"

class ofApp : public ofBaseApp {

public:
  void setup();
  void update();
  void draw();

  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void mouseEntered(int x, int y);
  void mouseExited(int x, int y);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  vector<ofPath> genLetterPaths(float circleRad);
  void drawLetters(ofColor fill, bool includeL = true);
  void updateMask(float offsetX, float offsetY);

  ofRectangle getBoundingBoxOfPath(ofPath &path);

  ofColor red;
  ofColor blue;
  ofColor cyan;

  float maxMouseOffset;
  float currentMouseXOffset;
  float currentMouseYOffset;

  float circleRadius;
  ofPath letterPath;
  ofPath letterPathNoL;

  ofFbo letterPathFbo;
  ofFbo letterPathMaskFbo;
};
