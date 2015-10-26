/*
 * =============================================================================
 *
 *       Filename:  buttonandroid.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 22:02:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef BUTTONANDROID_H
#define BUTTONANDROID_H

#include "button.h"

class ButtonAndroid : public Button {
    public:
        void draw() { std::cout << "Dibujando Boton Android." << std::endl; }
};

#endif
