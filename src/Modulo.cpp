//
//  Modulo.cpp
//  kouros_01
//
//  Created by DIEGO AMOZOO on 1/6/16.
//
//

#include "Modulo.hpp"

//--------------------------------------------------------------
void Modulo::setup(){
}

//--------------------------------------------------------------
void Modulo::draw(){
    for (int i = 0; i < NUM_CASILLAS; i++) {
        casillas[i].draw();
    }
}

//--------------------------------------------------------------
void Modulo::addCasilla(Casilla cas){
    casillas.push_back(cas);
}