/*
 * =============================================================================
 *
 *       Filename:  square.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 19:05:17
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape {
    public:
        Square(double side) : side(side) {}
        double getArea() { return side * side; }
    private:
        double side;
};

#endif
