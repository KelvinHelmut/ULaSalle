/*
 * =============================================================================
 *
 *       Filename:  debiangnomebuilder.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 23:51:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef DEBIANGNOMEBUILDER_H
#define DEBIANGNOMEBUILDER_H

#include "gnulinuxbuilder.h"

class DebianGnomeBuilder : public GnuLinuxBuilder {
    public:
        void buildEnvironmentDesktop();
        void buildWindowManager();
        void buildShell();
};

void DebianGnomeBuilder::buildEnvironmentDesktop() {
    this->gnuLinux->setEnvironmentDesktop("Gnome");
}

void DebianGnomeBuilder::buildWindowManager() {
    this->gnuLinux->setWindowManager("metacity");
}

void DebianGnomeBuilder::buildShell() {
    this->gnuLinux->setShell("bash");
}

#endif
