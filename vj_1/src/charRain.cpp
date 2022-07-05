#include <string>
#include "charRain.h"

#define GLSL120(shader) "#version 120\n" #shader

std::string randNum() {
	std::string nums = "";
	for (int i = 0; i < 10; i++) {
		double n = ofRandom(9) * ofNoise(ofRandom(10000), ofGetFrameNum() * 0.08);
		nums += std::to_string((int)n);
	}
	return nums;
}

//--------------------------------------------------------------
void charRain::setup() {
	ofSetFrameRate(60);
	ofBackground(40, 40, 68);
	ofSetColor(250);
	this->font.loadFont("fonts/HiraginoSans.ttf", 28, true, true, true);
	shader.load("vert.vert", "frag.frag");
}

//--------------------------------------------------------------
void charRain::update() {
	ofSeedRandom(39);
	double p = sin(ofGetFrameNum());
	ofTranslate(200 + ofGetFrameNum(), 200 * p);
}

//--------------------------------------------------------------
void charRain::draw() {
	ofColor colorOne(255, 0, 0, 0.7);
	ofColor colorTwo(0, 0, 0, 0.7);

	shader.begin();
	shader.setUniform1f("u_time", ofGetElapsedTimef());
	shader.setUniform2f("u_resolution", ofGetWidth(), ofGetHeight());
	shader.setUniform2f("u_mouse", ofGetMouseX(), ofGetMouseY());

	ofSetColor(255);
	ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
	shader.end();

	ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
	for (int i = 0; i < 100; i++) {
		ofPushMatrix();
		auto location = glm::vec3(ofRandom(-ofGetWidth(), ofGetWidth()), ofRandom(-ofGetHeight(), ofGetHeight()), ofRandom(-720, 720));
		ofTranslate(location);
		ofRotateX(ofMap(ofNoise(ofRandom(10000), ofGetFrameNum() * 0.005), 0, 1, -380, 320));
		ofRotateY(ofMap(ofNoise(ofRandom(10000), ofGetFrameNum() * 0.005), 0, 1, -380, 380));
		ofRotateZ(ofMap(ofNoise(ofRandom(10000), ofGetFrameNum() * 0.005), 0, 1, -210, 380));
		ofDrawBitmapString("Tokyo-v." + randNum(), 100, 100);
		ofPopMatrix();
	}
}

//--------------------------------------------------------------
void charRain::keyPressed(int key) {

}

//--------------------------------------------------------------
void charRain::keyReleased(int key) {

}

//--------------------------------------------------------------
void charRain::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void charRain::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void charRain::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void charRain::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void charRain::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void charRain::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void charRain::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void charRain::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void charRain::dragEvent(ofDragInfo dragInfo) {

}
