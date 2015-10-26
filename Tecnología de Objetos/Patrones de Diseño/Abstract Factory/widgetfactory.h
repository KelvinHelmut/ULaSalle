/*
 * =============================================================================
 *
 *       Filename:  widgetfactory.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 21:44:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H

#include "widget.h"

class WidgetFactory {
    public:
        enum Type { BUTTON, TEXTEDIT };
        virtual Widget * createWidget(Type type) = 0;
};

#endif
