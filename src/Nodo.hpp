//
//  Nodo.hpp
//  kouros_01
//
//  Created by DIEGO AMOZOO on 1/7/16.
//
//

#ifndef Nodo_hpp
#define Nodo_hpp

#pragma once
#include <stdio.h>
#include "ofMain.h"
#endif /* Nodo_hpp */

class Nodo{
public:
    bool isDefault;
    int id;
    bool inOu;
    bool isSelected;
    Nodo(int _id = 0, bool _isDefault = 0, bool _inOu = 0, bool _isSelected = 0) :
    id(_id), isDefault(_isDefault), inOu(_inOu), isSelected(_isSelected){
    }
    
    float x;
    float y;
    
    vector<ofVec3f> outConnections;
    vector<int> inConnections;
    
    void setup(bool);
    void draw();
    void setId(int);
    void getId();
};