/*
 * =============================================================================
 *
 *       Filename:  circle.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 18:51:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

#define PI 3.14159265359

class Circle : public Shape {
    public:
        Circle(double radius) : radius(radius) {}
        double getArea() { return PI * radius * radius; }
    private:
        double radius;
};

#endif
