#pragma once

#include "ofMain.h"

struct DisplayText {
	ofVec3f color;
	std::string text;
	ofVec2f position;
	std::string direction;
	float blightness;
};

class textBanner : public ofBaseApp {
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

	ofTrueTypeFont font;
	std::vector<DisplayText> displayTexts;
};
