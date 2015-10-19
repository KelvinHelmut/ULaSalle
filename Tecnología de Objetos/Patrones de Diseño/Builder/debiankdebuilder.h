/*
 * =============================================================================
 *
 *       Filename:  debiankdebuilder.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 23:53:13
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef DEBIANKDEBUILDER_H
#define DEBIANKDEBUILDER_H

#include "gnulinuxbuilder.h"

class DebianKdeBuilder : public GnuLinuxBuilder {
    public:
        void buildEnvironmentDesktop();
        void buildWindowManager();
        void buildShell();
};

void DebianKdeBuilder::buildEnvironmentDesktop() {
    this->gnuLinux->setEnvironmentDesktop("KDE");
}

void DebianKdeBuilder::buildWindowManager() {
    this->gnuLinux->setWindowManager("kwin");
}

void DebianKdeBuilder::buildShell() {
    this->gnuLinux->setShell("bash");
}

#endif
