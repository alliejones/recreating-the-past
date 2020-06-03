#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

  public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    ofxPanel gui;

    ofParameter<int> squareOneMargin;
    ofParameter<int> squareOneWidth;
    ofParameter<float> squareOneDropoff;

    ofParameter<int> squareOneJitter;
    ofParameter<int> squareTwoJitter;
    ofParameter<int> squareTwoMargin;
    ofParameter<int> squareTwoWidth;
    ofParameter<float> squareTwoDropoff;

    bool showGUI;
    
    private:
        void drawWithShape();
        void randomQuad(int width, int jitter, int margin);
        void randomQuadPolyline(int width, int jitter, int margin);
        void randomVertex(int x, int y, int amt);
    
        bool mouseIsPressed;
};
