/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 22:44:38
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include "singleobject.h"
#include <iostream>

int main(void) {
    SingleObject * s1 = SingleObject::getInstance();
    SingleObject * s2 = SingleObject::getInstance();

    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    return 0;
}
