//
//  Modulo.hpp
//  kouros_01
//
//  Created by DIEGO AMOZOO on 1/6/16.
//
//

#ifndef Modulo_hpp
#define Modulo_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Casilla.hpp"
#define NUM_CASILLAS 16

#endif /* Modulo_hpp */

class Modulo{
public:
    vector<Casilla> casillas;
    
    void setup();
    void draw();
    void addCasilla(Casilla);
    
};
