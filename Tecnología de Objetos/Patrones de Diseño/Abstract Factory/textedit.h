/*
 * =============================================================================
 *
 *       Filename:  textedit.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 21:48:04
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef TEXTEDIT_H
#define TEXTEDIT_H

#include "widget.h"

class TextEdit : public Widget{
    public:
        virtual void draw() = 0;
};

#endif
