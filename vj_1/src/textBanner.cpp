#include <math.h>
#include <random>
#include "textBanner.h"

std::vector<ofVec3f> colors = {
	ofVec3f (210, 213, 210),
	ofVec3f (249, 240, 235),
	ofVec3f (210, 210, 210),
	ofVec3f (230, 230, 230)
};

//--------------------------------------------------------------
void textBanner::setup() {
	ofSetVerticalSync(true);
	ofBackground(0, 5, 5);
	ofSetFrameRate(90);
	ofTrueTypeFont::setGlobalDpi(72);
	font.load("fonts/Noto_Sans_JP/NotoSansJP-Black.otf", 190);
	//font.load("Noto_Serif_JP/NotoSerifJP-Medium.otf", 190);
	font.setLineHeight(180);
	font.setLetterSpacing(0.8);
	int width = 860;
	int height = 160;
	int previousColorIndex = -1;
	for (int i = 0; i < 14; i++) {
		for (int j = 0; j < 50; j++) {
			std::mt19937 mt;
			std::random_device rnd;
			mt.seed(rnd());
			int currentIndex = mt() % (colors.size() - 1);
			if (previousColorIndex == currentIndex) {
				currentIndex += 1;
				if (currentIndex > colors.size() - 1) {
					currentIndex = 0;
				}
			}
			ofVec3f currentColor = colors.at(currentIndex);
			previousColorIndex = currentIndex;
			int posX = -(width * 50 / 2) + width * j;
			std::string direction = "right";
			/*
			if (i % 2 == 1) {
				posX -= width / 2;
				direction = "left";
			}
			*/
			int posY = -30 + height * i;
			ofVec2f position(posX, posY);
			DisplayText displayText = {
				currentColor,
				"CATCLUB",
				position,
				direction,
			};
			displayTexts.push_back(displayText);
		}
	}
}

//--------------------------------------------------------------
void textBanner::update() {
	float elapsed = ofGetElapsedTimef();
	// 色をn秒ごとに切り替える
	// n / 2 % 1 == 0のタイミングでずらす
	cout << elapsed << endl;
	float n = 0.81;
	if (fmod(elapsed, n) <= 0.02) {
		ofVec3f previousColor = displayTexts.at(0).color;
		displayTexts.at(0).color = displayTexts.at(displayTexts.size() - 1).color;
		for (int i = 1; i < displayTexts.size(); i++) {
			ofVec3f newColor = previousColor;
			previousColor = displayTexts.at(i).color;
			displayTexts.at(i).color = newColor;
		}
	}
	for (int i = 0; i < displayTexts.size(); i++) {
		DisplayText displayText = displayTexts.at(i);
		ofVec2f newPosition(displayText.position.x, displayText.position.y);
		int currentRow = i / 50;
		int speed = 9;
		switch (currentRow) {
		case 1:
			speed = 16;
			break;
		case 2:
			speed = 18;
			break;
		case 3:
			speed = 13;
			break;
		case 4:
			speed = 15;
			break;
		case 5:
			speed = 11;
			break;
		case 6:
			speed = 35;
			break;
		case 7:
			speed = 9;
		}
		int e = 1;
		// displayTexts.at(i).blightness = ofMap(e, 0, 1, 0, 255, true);
		if (displayText.direction == "right") {
			newPosition.x += speed;
		}
		else {
			newPosition.x -= speed;
		}
		displayTexts.at(i).position = newPosition;
	}
}

//--------------------------------------------------------------
void textBanner::draw() {
	for (int i = 0; i < displayTexts.size(); i++) {
		DisplayText displayText = displayTexts.at(i);
		ofColor c = ofColor(displayText.color.x, displayText.color.y, displayText.color.z);
		//c.setBrightness(displayText.blightness);
		ofSetColor(c);
		font.drawString(displayText.text, displayText.position.x, displayText.position.y);
	}
}

//--------------------------------------------------------------
void textBanner::keyPressed(int key) {

}

//--------------------------------------------------------------
void textBanner::keyReleased(int key) {

}

//--------------------------------------------------------------
void textBanner::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void textBanner::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void textBanner::mousePressed(int x, int y, int button) {
	x += 5;
}

//--------------------------------------------------------------
void textBanner::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void textBanner::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void textBanner::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void textBanner::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void textBanner::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void textBanner::dragEvent(ofDragInfo dragInfo) {

}
