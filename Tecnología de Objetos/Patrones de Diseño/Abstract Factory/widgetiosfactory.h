/*
 * =============================================================================
 *
 *       Filename:  widgetiosfactory.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 21:46:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef WIDGETIOSFACTORY_H
#define WIDGETIOSFACTORY_H

#include "widgetfactory.h"
#include "buttonios.h"
#include "texteditios.h"

class WidgetIosFactory : public WidgetFactory {
    public:
        Widget * createWidget(Type type) {
            switch (type) {
                case BUTTON: return new ButtonIos();
                case TEXTEDIT: return new TextEditIos();
            }
        }
};

#endif
