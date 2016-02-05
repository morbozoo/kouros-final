#pragma once

#include "ofMain.h"
#include "Modulo.hpp"
#include "Casilla.hpp"
#include "ofxJSON.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
    vector<Modulo> modules;
    vector<vector<Modulo> > BKP;
    ofVec2f selected;
    ofVec3f nodoSelected;
    int nodoCount;
    ofVec3f first;
    ofVec3f second;
    bool dragged;
    ofVec2f draggedPos;
    bool draggedIn;
    bool draggedOut;
    int skip;
    
    vector<string> actions;
    vector<Casilla> origenes;
    vector<Casilla> destinos;
    void addAction();
    void unDo();
    bool drawUnDo;
    int willUnDo;
    
    vector<vector<float> > cola;
    
    bool enableInConnect;
    bool enableOutConnect;
    bool enableDeleteInConnect;
    bool enableDeleteOutConnect;
    bool editModeOn;
    
    ofxPanel             gui;
    bool                 mHideGUI;
    
    void                 saveGUIValues();
    
		void setup();
		void update();
		void draw();
        void play(vector<ofVec3f>);
        void copy();
        void setupGUI();
        void loadSound();
        void borrarConexiones();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //JSON for writing and reading points
    ofxJSONElement 		    mJSON;
    
    void                  loadJSON(string);
    void 				  saveJSON(string);
    void                  startJSON();
    void processOpenFileSelection(ofFileDialogResult openFileResult);
    
    int count;
    
    int soundSelector;
    vector<int> soundBanks;
    
    ofxSlider<float>       velSlider;
    vector<ofxSlider<int> >         soundSlider;

    ofxButton      loadSoundBank;
    
    vector<ofVec3f> copys;
		
};
