/*
 * =============================================================================
 *
 *       Filename:  button.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 21:47:41
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef BUTTON_H
#define BUTTON_H

#include "widget.h"

class Button : public Widget {
    public:
        virtual void draw() = 0;
};

#endif
