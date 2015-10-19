/*
 * =============================================================================
 *
 *       Filename:  texteditios.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 22:06:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef TEXTEDITIOS_H
#define TEXTEDITIOS_H

#include "textedit.h"

class TextEditIos : public TextEdit {
    public:
        void draw() { std::cout << "Dibujando TextEdit iOS." << std::endl; }
};

#endif
