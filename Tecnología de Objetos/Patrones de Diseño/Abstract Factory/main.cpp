/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 22:12:58
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include "widgetandroidfactory.h"
#include "widgetiosfactory.h"

int main(void) {
    WidgetFactory * factory;
    Widget * widget;

    factory = new WidgetAndroidFactory();
    widget = factory->createWidget(WidgetFactory::BUTTON);
    widget->draw();
    widget = factory->createWidget(WidgetFactory::TEXTEDIT);
    widget->draw();

    factory = new WidgetIosFactory();
    widget = factory->createWidget(WidgetFactory::BUTTON);
    widget->draw();
    widget = factory->createWidget(WidgetFactory::TEXTEDIT);
    widget->draw();

    return 0;
}
