#include "ofMain.h"
#include "flashArt.h"
#include "flashTriangles.h"
#include "textBanner.h"
#include "charRain.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1920,1080,OF_WINDOW);			// <-------- setup the GL context
	// ofRunApp(new flashArt());
	// ofRunApp(new flashTriangles());
	// ofRunApp(new textBanner());
	ofRunApp(new charRain());
}
