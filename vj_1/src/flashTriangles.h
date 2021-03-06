#pragma once

#include "ofMain.h"

class flashTriangles : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		void initVectors();

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

		ofMesh mesh;
		// 1三角形で3つ() -> 全画面分
		std::vector<std::vector<ofVec2f>> triangles;
		std::vector<std::vector<unsigned int>> triangleThresholds;
		float random;
};
