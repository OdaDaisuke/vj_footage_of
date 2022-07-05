#include "flashArt.h"

int currentImageIdx;
int lastImageUpdatedAt;
int defaultImageWidth;
int defaultImageHeight;
int imageWidth;
int imageHeight;
int alpha;

//--------------------------------------------------------------
void flashArt::setup(){
	ofSetVerticalSync(true);
	ofBackground(233,233,233);
	for (int i = 0; i < 5; i++) {
		std::string idx = to_string(i + 1);
		std::string filename = "image_" + idx + ".jpg";
		images[i].load(filename);
	}
	currentImageIdx = 0;
	lastImageUpdatedAt = ofGetSystemTimeMillis();
	imageHeight = ofGetHeight();
	imageWidth = ofGetWidth();
	defaultImageHeight = ofGetHeight();
	defaultImageWidth = ofGetWidth();
	shaderGlitch.setup();
}

//--------------------------------------------------------------
void flashArt::update(){
	int m = ofGetSystemTimeMillis();
	int imageSwitchThreshold = 125;
	int diffWidth = imageWidth - defaultImageWidth;
	int diffHeight = imageHeight - defaultImageHeight;
	imageHeight += 15;
	imageWidth += 16;
	if (lastImageUpdatedAt + imageSwitchThreshold < m) {
		imageHeight = defaultImageHeight;
		imageWidth = defaultImageWidth;

		if (currentImageIdx == 4) {
			currentImageIdx = 0;
		} else {
			currentImageIdx += 1;
		}
		lastImageUpdatedAt = m;
	}
}

//--------------------------------------------------------------
void flashArt::draw(){
	ofSetColor(ofColor::white);
	if (ofGetSystemTimeMillis() % 605 < 131) {
		shaderGlitch.begin();
		int diffWidth = imageWidth - defaultImageWidth;
		int diffHeight = imageHeight - defaultImageHeight;
		images[currentImageIdx].draw(-diffWidth, -diffHeight, imageWidth + diffWidth, imageHeight + diffHeight);
		shaderGlitch.end();
	}
	else {
		int diffWidth = imageWidth - defaultImageWidth;
		int diffHeight = imageHeight - defaultImageHeight;
		images[currentImageIdx].draw(-diffWidth, -diffHeight, imageWidth + diffWidth, imageHeight + diffHeight);
	}
	if (ofGetSystemTimeMillis() % 185 < 21) {
		ofDrawRectangle(0, 0, defaultImageWidth, defaultImageHeight);
	}
}

//--------------------------------------------------------------
void flashArt::keyPressed(int key){

}

//--------------------------------------------------------------
void flashArt::keyReleased(int key){

}

//--------------------------------------------------------------
void flashArt::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void flashArt::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void flashArt::mousePressed(int x, int y, int button){
	x += 5;
}

//--------------------------------------------------------------
void flashArt::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void flashArt::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void flashArt::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void flashArt::windowResized(int w, int h){

}

//--------------------------------------------------------------
void flashArt::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void flashArt::dragEvent(ofDragInfo dragInfo){

}
