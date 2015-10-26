/*
 * =============================================================================
 *
 *       Filename:  widgetandroidfactory.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 21:45:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef WIDGETANDROIDFACTORY_H
#define WIDGETANDROIDFACTORY_H

#include "widgetfactory.h"
#include "buttonandroid.h"
#include "texteditandroid.h"

class WidgetAndroidFactory : public WidgetFactory {
    public:
        Widget * createWidget(Type type) {
            switch (type) {
                case BUTTON: return new ButtonAndroid();
                case TEXTEDIT: return new TextEditAndroid();
            }
        }
};

#endif
