//
//  Casilla.hpp
//  kouros_01
//
//  Created by DIEGO AMOZOO on 1/6/16.
//
//

#ifndef Casilla_hpp
#define Casilla_hpp
#pragma once
#include <stdio.h>
#include "ofMain.h"
#include "Nodo.hpp"
#define SIZE_CASILLA 40
#define SIZE_CUAD 15
#define INPUT_X_POS 25
#define INPUT_Y_POS 25
#define OUTPUT_X_POS 25
#define OUTPUT_Y_POS 0


#endif /* Casilla_hpp */

class Casilla{
public:
    float x, y;
    int  id;
    int soundBank;
    bool  isSelected;
    Casilla(float _x = 0, float _y = 0, int _id = 0, bool _isSelected = 0) :
    x(_x), y(_y), id(_id), isSelected(_isSelected){
    }
    
    vector<Nodo> inputs;
    vector<Nodo> outputs;
    ofVec2f saved;
    
    void setup(int);
    void connect();
    void draw();
    void updatePos(float, float);
    void updateId(int);
    void setSaved(ofVec2f);
    vector<ofVec3f> play(bool, int);
    void updatePlayer(int);
    
    ofSoundPlayer player;

};