/*
 * =============================================================================
 *
 *       Filename:  texteditandroid.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 22:04:18
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef TEXTEDITANDROID_H
#define TEXTEDITANDROID_H

#include "textedit.h"

class TextEditAndroid : public TextEdit {
    public:
        void draw() { std::cout << "Dibujando TextEdit Android." << std::endl; }
};

#endif
