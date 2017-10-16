//--------------------------------------------------------------
// Celine Chappert
// 16 October 2017
// Assignment week 1 : Forgery
//
// THIS IS NOT MY CODE.
//
// I REPEAT : THIS IS NOT MY CODE !
//
// ALL CREDITS FOR THE CODE ON THIS FILE TO
// THE CREATOR(S) OF THE ofxPathFitter addon
//
// NOTE: I am using the library in the ofApp.cpp and ofApp.h
// files of this folder. When taking snippets of code from
// the lib credit is given in the form of comments around
// the code snippet.
//
//--------------------------------------------------------------

#pragma once

#include "ofMain.h"

#include "ofxPathFitter.h"

#define SELECTPADDING	10

#define POINT		0
#define HANDLEIN	1
#define HANDLEOUT	2

class Stroke
{
	void drawEditableVertex(BezPoint vertex);

public:
	Stroke();
	~Stroke();
	Stroke(int i);

	void clear();

	void draw();
	void drawActive(int smoothness);
	void drawEditable(int iSelectedVertex);

	void startStroke();
	void addVertex(ofVec2f v);
	void finishStroke(int smoothness);

	void updateBez();
	void updateLine(bool simplify = true);
	void modifyHandle(int id, int selectedHandle, int x, int y);
	void modifyVertex(int id, int x, int y);

	int getSelectedVertex(int iSelectedVertex, int &handle, int x, int y);
	static int getSelectedStroke(vector<Stroke> *strokes, ofVec2f mousePos);

	void translateLine(ofVec2f lastMousePos, int x, int y);

	ofPolyline line;
	vector<BezPoint> lineBez;

};
