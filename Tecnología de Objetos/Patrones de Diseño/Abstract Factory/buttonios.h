/*
 * =============================================================================
 *
 *       Filename:  buttonios.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 22:07:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef BUTTONIOS_H
#define BUTTONIOS_H

#include "button.h"

class ButtonIos : public Button {
    public:
        void draw() { std::cout << "Dibujando Boton iOS." << std::endl; }
};

#endif
