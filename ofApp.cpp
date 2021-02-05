#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	ofSetBackgroundColor(0);
	numSegments = 1060;
	initSpiroMesh(myMesh, 200.0f);
}

//--------------------------------------------------------------
void ofApp::initSpiroMesh(ofMesh &curMesh, float r) {

	curMesh.setMode(OF_PRIMITIVE_TRIANGLES);

	// Add vertices around the circumference
	for (int i = 0; i < numSegments; i++) {
		float theta = 360.0f * i / numSegments;
		float x = r * sin(ofDegToRad(theta));
		float y = r * cos(ofDegToRad(theta));
		curMesh.addVertex(vec3(x, y, 0));
		ofColor curColor;
		curColor.setHsb(theta * 255 / 360, 255, 255);
		curMesh.addColor(curColor);
	}

	// Add central vertex
	curMesh.addVertex(vec3(0, 0, -100));
	curMesh.addColor(ofColor::white);


	// Get the index of the central vertex
	int vIndexCentre = curMesh.getNumVertices() - 1;

	// Add the triangles using vertex indices
	for (int i = 0; i < numSegments; i++) {
		int vIndex0 = i;
		int vIndex1 = i + 1;
		if (vIndex1 >= numSegments) {
			vIndex1 = 0;
		}
		curMesh.addTriangle(vIndex0, vIndex1, vIndexCentre);

		/*curMesh.addColor(ofColor::black);
		curMesh.addVertices(vIndex0+10, vIndex1, vIndexCentre);*/
	}

}
//--------------------------------------------------------------
void ofApp::updateSpiroMesh(ofMesh &curMesh, float r, float rMult, int freqMult, float phase) {
	// Calculate new positions for the vertices around the circumference
	for (int i = 0; i < numSegments; i++) {
		float theta = 360.0f * i / numSegments;
		float x = r * sin(ofDegToRad(theta));
		float y = r * cos(ofDegToRad(theta));
		x += r * rMult * sin(ofDegToRad(freqMult * theta + phase));
		y += r * rMult * cos(ofDegToRad(freqMult * theta + phase));
		x += r * pow(rMult, 2) * sin(ofDegToRad(pow(freqMult, 2) * theta + phase));
		y += r * pow(rMult, 2) * cos(ofDegToRad(pow(freqMult, 2) * theta + phase));
		curMesh.setVertex(i, vec3(x, y, 0));
	}
}
//--------------------------------------------------------------
void ofApp::update(){

		float time = ofGetElapsedTimef();
		float phase = 20.0f * time;
		updateSpiroMesh(myMesh, 200.0f, 0.5, 8, phase);
		updateSpiroMesh(myMesh2, 50.0f, 0.3, 5, phase);

}

//--------------------------------------------------------------
void ofApp::draw(){

	ofTranslate(0.5f * ofGetWidth(), 0.5f * ofGetHeight());
	myMesh.draw();
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
