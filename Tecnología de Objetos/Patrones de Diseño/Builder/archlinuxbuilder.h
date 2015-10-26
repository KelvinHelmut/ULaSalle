/*
 * =============================================================================
 *
 *       Filename:  archlinuxbuilder.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 23:54:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef ARCHLINUXBUILDER_H
#define ARCHLINUXBUILDER_H

#include "gnulinuxbuilder.h"

class ArchlinuxBuilder : public GnuLinuxBuilder {
    public:
        void buildEnvironmentDesktop();
        void buildWindowManager();
        void buildShell();
};

void ArchlinuxBuilder::buildEnvironmentDesktop() {
    this->gnuLinux->setEnvironmentDesktop("none");
}

void ArchlinuxBuilder::buildWindowManager() {
    this->gnuLinux->setWindowManager("i3");
}

void ArchlinuxBuilder::buildShell() {
    this->gnuLinux->setShell("zsh");
}

#endif
