//
//  Nodo.cpp
//  kouros_01
//
//  Created by DIEGO AMOZOO on 1/7/16.
//
//

#include "Nodo.hpp"

//--------------------------------------------------------------
void Nodo::draw(){

    ofPushStyle();
    if (isDefault) {
        ofSetColor(0, 102, 204);
    }else{
        ofSetColor(130, 130, 130);
    }
//    if (isPlaying) {
//        ofSetColor(0, 255, 255);
//    }
    ofRect(0, 0, 20, 20);
    if (inOu) {
        ofSetColor(153, 0, 153);
    }else{
        ofSetColor(0, 0, 153);
    }
    
    
    ofCircle(10, 10, 3);
    ofPushStyle();
    ofSetColor(30, 30, 30);
    ofSetLineWidth(3);
    ofNoFill();
    ofRect(0, 0, 20, 20);
    ofPopStyle();
    ofPopStyle();
}

//--------------------------------------------------------------
void Nodo::setId(int newId){
    id = newId;
}

//--------------------------------------------------------------
void Nodo::getId(){
    return id;
}