#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
  red = ofColor(236, 78, 68);
  blue = ofColor(0, 108, 185);
  cyan = ofColor(0, 163, 218);

  maxMouseOffset = 15.;
  currentMouseXOffset = 0;
  currentMouseYOffset = 0;

  circleRadius = 75.;

  letterPath.setCircleResolution(100);
  letterPathNoL.setCircleResolution(100);

  vector<ofPath> paths = ofApp::genLetterPaths(circleRadius);
  for (int i = 0; i < paths.size(); i++) {
    letterPath.append(paths[i]);
    if (i != paths.size() - 1) {
      letterPathNoL.append(paths[i]);
    }
  }

  ofRectangle letterPathBounds = ofApp::getBoundingBoxOfPath(letterPath);
  letterPathFbo.allocate(letterPathBounds.getWidth() + maxMouseOffset * 2,
                         letterPathBounds.getHeight() + maxMouseOffset * 2);
  letterPathMaskFbo.allocate(letterPathBounds.getWidth() + maxMouseOffset * 2,
                             letterPathBounds.getHeight() + maxMouseOffset * 2);

  letterPathFbo.begin();
  ofClear(0, 0, 0);
  // y translation needs to accomodate ascenders
  ofTranslate(circleRadius, circleRadius * 4. / 3);
  letterPath.setColor(cyan);
  letterPath.draw();
  letterPathFbo.end();
}

//--------------------------------------------------------------
void ofApp::update() {
  currentMouseXOffset =
      ofMap(mouseX, 0, ofGetWindowWidth(), -maxMouseOffset, maxMouseOffset);
  currentMouseYOffset =
      ofMap(mouseY, 0, ofGetWindowHeight(), -maxMouseOffset, maxMouseOffset);
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofBackground(60, 49, 72);

  ofTranslate(100, 100);

  letterPathNoL.setColor(red);
  letterPathNoL.draw(circleRadius * 8. / 3, circleRadius * 2);

  letterPath.setColor(blue);
  letterPath.draw(circleRadius * 2 + currentMouseXOffset,
                  circleRadius * 2 + currentMouseYOffset);

  updateMask(currentMouseXOffset, currentMouseYOffset);
  letterPathFbo.draw(circleRadius + currentMouseXOffset,
                     circleRadius * 2. / 3 + currentMouseYOffset);
}

void ofApp::updateMask(float offsetX, float offsetY) {
  letterPathMaskFbo.begin();
  ofClear(255, 0, 0);
  letterPathNoL.setColor(255);
  // y translation needs to accomodate ascenders
  letterPathNoL.draw(circleRadius * (5. / 3) - currentMouseXOffset,
                     circleRadius * (4. / 3) - currentMouseYOffset);
  letterPathMaskFbo.end();

  letterPathFbo.getTexture().setAlphaMask(letterPathMaskFbo.getTexture());
}

vector<ofPath> ofApp::genLetterPaths(float circleRad) {
  float circleRadThird = circleRad / 3.;

  vector<char> letters = {'c', 'o', 'b', 'o'};
  vector<ofPath> letterPaths;

  for (int i = 0; i < letters.size(); i++) {
    char letter = letters[i];
    ofPath path;
    path.setCircleResolution(100);

    if (letter == 'b') {
      ofPath circle;
      circle.setCircleResolution(100);
      circle.circle(0, 0, circleRad);

      ofPolyline rect = ofPolyline::fromRectangle(
          ofRectangle(-circleRad, -circleRad - circleRadThird,
                      circleRad - circleRadThird, circleRad + circleRadThird));
      rect.close();
      // clipper uses integers internally, scale up for smoother curves
      rect.scale(10, 10);

      ofPolyline circ = circle.getOutline()[0];
      circ.close();
      circ.scale(10, 10);

      ofx::Clipper clipper;
      clipper.addPolyline(circ, ClipperLib::ptSubject);
      clipper.addPolyline(rect, ClipperLib::ptClip);
      ofPolyline result = clipper.getClipped(ClipperLib::ClipType::ctUnion)[0];
      result.scale(0.1,
                   0.1); // undo scaling for clipper

      path.moveTo(result[0]);
      for (size_t i = 1; i < result.size(); ++i) {
        path.lineTo(result[int(i)]);
      }
    } else {
      path.circle(0, 0, circleRad);
    }

    if (letter == 'c') {
      path.rectangle(circleRadThird, -1, circleRad - circleRadThird, 2);
    }

    path.circle(0, 0, circleRadThird);

    path.translate(glm::vec2(i * circleRad * 2, 0));

    letterPaths.push_back(path);
  }

  ofPath pathL;
  pathL.rectangle(0, -circleRad - circleRadThird, circleRad - circleRadThird,
                  circleRad * 2 + circleRadThird);
  pathL.translate(
      glm::vec2(circleRad * 2 * (letters.size() - 1) + circleRad, 0));
  letterPaths.push_back(pathL);

  return letterPaths;
}

ofRectangle ofApp::getBoundingBoxOfPath(ofPath &path) {
  ofRectangle rect;
  for (int i = 0; i < path.getOutline().size(); i++) {
    ofRectangle b = path.getOutline().at(i).getBoundingBox();
    if (i == 0)
      rect = b;
    else
      rect.growToInclude(b);
  }
  return rect;
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
