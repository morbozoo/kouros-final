//
//  Casilla.cpp
//  kouros_01
//
//  Created by DIEGO AMOZOO on 1/6/16.
//
//

#include "Casilla.hpp"

//--------------------------------------------------------------
void Casilla::draw(){
    ofPushMatrix();
    ofTranslate(x, y);
    
    ofPushStyle();
    if (isSelected || player.getIsPlaying()) {
        ofSetColor(0, 255, 255);
    }else{
        ofSetColor(0, 102, 204);
    }
    ofRect(0, 0, SIZE_CASILLA, SIZE_CASILLA);
    
    
    ofSetColor(0, 0, 153);
    ofRect(OUTPUT_X_POS, OUTPUT_Y_POS, SIZE_CUAD, SIZE_CUAD);
    ofSetColor(153, 0, 153);
    ofRect(INPUT_X_POS, INPUT_Y_POS, SIZE_CUAD, SIZE_CUAD);
    ofSetColor(255, 255, 255);
    ofLine(OUTPUT_X_POS + 8, OUTPUT_Y_POS, OUTPUT_X_POS + 8, SIZE_CUAD);
    ofLine(OUTPUT_X_POS, OUTPUT_Y_POS + 8, OUTPUT_X_POS + SIZE_CUAD, OUTPUT_Y_POS + 8);
    ofLine(INPUT_X_POS + 8, INPUT_Y_POS, INPUT_X_POS + 8, INPUT_Y_POS + SIZE_CUAD);
    ofLine(INPUT_X_POS, INPUT_Y_POS + 8, INPUT_X_POS + SIZE_CUAD, INPUT_Y_POS + 8);
    ofPopStyle();
    ofPushMatrix();
    ofTranslate(-SIZE_CASILLA + 15, 0);
    ofSetColor(0, 0, 153);
    ofRect(OUTPUT_X_POS, OUTPUT_Y_POS, SIZE_CUAD, SIZE_CUAD);
    ofSetColor(153, 0, 153);
    ofRect(INPUT_X_POS, INPUT_Y_POS, SIZE_CUAD, SIZE_CUAD);
    ofSetColor(255, 255, 255);
    ofLine(OUTPUT_X_POS, OUTPUT_Y_POS + 8, OUTPUT_X_POS + SIZE_CUAD, OUTPUT_Y_POS + 8);
    ofLine(INPUT_X_POS, INPUT_Y_POS + 8, INPUT_X_POS + SIZE_CUAD, INPUT_Y_POS + 8);
    ofPopStyle();
    ofPopMatrix();
    
    if (isSelected || player.getIsPlaying()) {
        ofSetColor(30, 30, 30);
    }
    else{
        ofSetColor(230, 230, 230);
    }
    ofDrawBitmapString(ofToString(id), 5, 20);
    
    ofPushStyle();
    ofSetColor(30, 30, 30);
    ofSetLineWidth(3);
    ofNoFill();
    ofRect(0, 0, SIZE_CASILLA, SIZE_CASILLA);
    ofPopStyle();
    
    ofTranslate(SIZE_CASILLA, 0);
    for (int i = 0; i < outputs.size(); i++) {
        ofPushMatrix();
        ofTranslate(i * SIZE_CASILLA/2, 0);
        outputs[i].draw();
        ofPopMatrix();
    }
    ofTranslate(0, SIZE_CASILLA/2);
    for (int i = 0; i < inputs.size(); i++) {
        ofPushMatrix();
        ofTranslate(i * SIZE_CASILLA/2, 0);
        inputs[i].draw();
        ofPopMatrix();
    }
    
    for (int i = 0; i < inputs.size(); i++) {
        for (int j = 0; j < inputs[i].inConnections.size(); j++) {
            ofPushStyle();
            ofSetColor(153, 0, 153, 180);
            ofSetLineWidth(3);
            ofLine(SIZE_CASILLA/4 + i*SIZE_CASILLA/2, SIZE_CASILLA/4, SIZE_CASILLA/4 + inputs[i].inConnections[j]*SIZE_CASILLA/2, -SIZE_CASILLA/4);
            ofPopStyle();
        }
    }
    
    
    ofPopMatrix();

}


//--------------------------------------------------------------
void Casilla::updatePos(float newx, float newy){
    x = newx;
    y = newy;
}

//--------------------------------------------------------------
void Casilla::updateId(int newId){
    id = newId;
}

//--------------------------------------------------------------
void Casilla::setup(int soundSelector){
    soundBank = soundSelector;
    string sound = "S" + ofToString(soundSelector) + "/ S" + ofToString(soundSelector) + "-" + ofToString(id) + ".wav";
    player.loadSound(sound);
}

//--------------------------------------------------------------
vector<ofVec3f> Casilla::play(bool editMode, int input){
    player.play();
    vector<ofVec3f> ret;
    if (!editMode) {
        for (int i = 0; i < inputs[input].inConnections.size(); i++) {
            for (int j = 0; j < outputs[inputs[input].inConnections[i]].outConnections.size(); j++) {
                ret.push_back(outputs[inputs[input].inConnections[i]].outConnections[j]);
            }
        }
    }
    return ret;
}

//--------------------------------------------------------------
void Casilla::updatePlayer(int newBank){
    soundBank = newBank;
    player.unloadSound();
    string sound = "S" + ofToString(newBank) + "/ S" + ofToString(newBank) + "-" + ofToString(id) + ".wav";
    player.loadSound(sound);
}

//--------------------------------------------------------------
void Casilla::setSaved(ofVec2f newSaved){
    saved = newSaved;
}