/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 19:09:12
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include <iostream>
#include "circle.h"
#include "shapefactory.h"

int main(void) {
    Shape *s;

    s = ShapeFactory::getShape(ShapeFactory::CIRCLE, 3);
    std::cout << s->getArea() << std::endl;

    s = ShapeFactory::getShape(ShapeFactory::SQUARE, 3);
    std::cout << s->getArea() << std::endl;

    return 0;
}
