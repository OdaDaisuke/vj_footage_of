#include <math.h>
#include <random>
#include "flashTriangles.h"

void log(string s) {
	std::cout << s << endl;
}

void flashTriangles::initVectors() {
	std::srand(time(NULL));
	float triangleRadius = 42.0;
	for (int y = 0; y <= 1080; y = y + 125) {
		for (int x = 0; x <= 16; x++) {
			for (int z = 0; z < 2; z++) {
				ofVec2f top(x * 120 + (5.0), 5.0 + y);
				ofVec2f left(x * 120 + (5.0), 120.0 + y);
				ofVec2f right(x * 120 + (120.0), 120.0 + y);
				if (z % 2 == 1) {
					top = ofVec2f((x - 1) * 120 + 10.0, 5.0 + y);
					left = ofVec2f(x * 120.0, 112.0 + y);
					right = ofVec2f(x * 120.0, 5.0 + y);
				}
				std::vector<ofVec2f> triangle = {
					top,
					left,
					right,
				};
				triangles.push_back(triangle);
				std::mt19937 mt;
				std::random_device rnd;
				mt.seed(rnd());
				std::vector<unsigned int> triangleThreshold = {
					mt(),
					mt(),
					mt(),
				};
				triangleThresholds.push_back(triangleThreshold);
			}
		}
	}
}

//--------------------------------------------------------------
void flashTriangles::setup() {
	ofSetVerticalSync(true);
	initVectors();
	ofBackground(0, 5, 5);
}

//--------------------------------------------------------------
void flashTriangles::update() {
}

//--------------------------------------------------------------
void flashTriangles::draw() {
	ofColor clr = ofColor::blue;
	ofColor subColor = ofColor(0.22, 0.4, 0.92);

	// ”’ -> Â”’
	for (int i = 0; i < triangles.size(); i++) {
		std::vector<ofVec2f> triangle = triangles.at(i);
		int elapsedTime = ofGetElapsedTimef() * 10;
		float seed1 = sin(elapsedTime + fmod(sqrt(i), 1.0) * 35);
		float seed2 = cos(elapsedTime + sqrt(i + i) * 15);
		float seed3 = tan(elapsedTime + sqrt(i + i));
		float speed1 = (seed1 > 0.8 && seed1 <= 1.0) ? seed1 : 0.0;
		float speed2 = (seed2 > 0.8 && seed2 <= 1.0) ? seed2 : 0.0;
		float speed3 = (seed3 > 0.7 && seed3 <= 0.9) ? seed3 : 0.0;
		clr.setBrightness(ofMap(speed1, 0, 1, 0, 255, true));
		subColor.setBrightness(ofMap(speed3 + speed3, 0, 1, 0, 255, true));
		ofSetColor(clr);
		ofLine(triangle[0].x, triangle[0].y, triangle[1].x, triangle[1].y);
		ofSetColor(subColor);
		ofLine(triangle[0].x + 3, triangle[0].y + 3, triangle[1].x + 1, triangle[1].y + 1);
		ofLine(triangle[0].x - 1, triangle[0].y - 2, triangle[1].x - 3, triangle[1].y + 3);

		clr.setBrightness(ofMap(speed2, 0, 1, 0, 255, true));
		subColor.setBrightness(ofMap(speed2 + speed2, 0, 1, 0, 255, true));
		ofSetColor(clr);
		ofLine(triangle[0].x, triangle[0].y, triangle[2].x, triangle[2].y);
		ofSetColor(subColor);
		ofLine(triangle[0].x + 3, triangle[0].y + 3, triangle[2].x + 1, triangle[2].y - 3);

		clr.setBrightness(ofMap(speed3, 0, 1, 0, 255, true));
		subColor.setBrightness(ofMap(speed2 + speed2, 0, 1, 0, 255, true));
		ofSetColor(clr);
		ofLine(triangle[1].x, triangle[1].y, triangle[2].x, triangle[2].y);
		ofSetColor(subColor);
		ofLine(triangle[1].x + 3, triangle[1].y + 3, triangle[2].x + 3, triangle[2].y + 3);
	}
}

//--------------------------------------------------------------
void flashTriangles::keyPressed(int key) {

}

//--------------------------------------------------------------
void flashTriangles::keyReleased(int key) {

}

//--------------------------------------------------------------
void flashTriangles::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void flashTriangles::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void flashTriangles::mousePressed(int x, int y, int button) {
	x += 5;
}

//--------------------------------------------------------------
void flashTriangles::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void flashTriangles::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void flashTriangles::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void flashTriangles::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void flashTriangles::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void flashTriangles::dragEvent(ofDragInfo dragInfo) {

}
