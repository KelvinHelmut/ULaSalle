/*
 * =============================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 23:57:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include "debiangnomebuilder.h"
#include "debiankdebuilder.h"
#include "archlinuxbuilder.h"
#include <iostream>

int main(void) {
    GnuLinuxBuilder * builder;
    GnuLinux * gnu;

    builder = new DebianGnomeBuilder();
    builder->createNewGnuLinux();
    gnu = builder->getGnuLinux();
    gnu->info();
    
    builder = new DebianKdeBuilder();
    builder->createNewGnuLinux();
    gnu = builder->getGnuLinux();
    gnu->info();

    builder = new ArchlinuxBuilder();
    builder->createNewGnuLinux();
    gnu = builder->getGnuLinux();
    gnu->info();


    return 0;
}
