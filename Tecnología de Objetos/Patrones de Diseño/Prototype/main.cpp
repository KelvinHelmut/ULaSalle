/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/10/15 01:28:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include "android18.h"
#include "android17.h"
#include <iostream>

int main(void) {
    AndroidClone * a;
    Android17 * a17 = new Android17(2300);
    Android18 * a18 = new Android18(3560);

    a = a17->clone();
    std::cout << a->getName() << " : " << a->getPower() << std::endl;

    a = a18->clone();
    std::cout << a->getName() << " : " << a->getPower() << std::endl;

    return 0;
}
