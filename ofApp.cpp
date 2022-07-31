#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(0);
	ofSetColor(255);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 40;
	for (int x = span * 0.5 + span; x < ofGetWidth() - span; x += span) {

		for (int y = span * 0.5 + span; y < ofGetHeight() - span; y += span) {

			auto noise_value = ofNoise(x * 0.0045, y * 0.0045, ofGetFrameNum() * 0.015);

			if (noise_value < 0.4) { noise_value = 0; }
			else if (noise_value < 0.6) { noise_value = ofMap(noise_value, 0.35, 0.6, 0, 1); }
			else { noise_value = 1; }

			int len = ofMap(noise_value, 0, 1, span * 0.5, span * 0.5 * sqrt(2));

			ofPushMatrix();
			ofTranslate(x, y);
			ofRotate(ofMap(noise_value, 0, 1, 0, 45));

			ofDrawLine(-len, 0, len, 0);
			ofDrawLine(0, -len, 0, len);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}