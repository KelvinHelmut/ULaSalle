/*
 * =============================================================================
 *
 *       Filename:  shapefactory.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 19:18:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include "circle.h"
#include "square.h"

class ShapeFactory {
    public:
        enum Type { CIRCLE, SQUARE };
        static Shape * getShape(Type type, double value) {
            switch (type) {
                case CIRCLE: return new Circle(value);
                case SQUARE: return new Square(value);
            }
            return 0;
        }
};
