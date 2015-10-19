/*
 * =============================================================================
 *
 *       Filename:  gnulinuxbuilder.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 23:37:39
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef GNULINUXBUILDER_H
#define GNULINUXBUILDER_H

#include "gnulinux.h"

class GnuLinuxBuilder {
    public:
        GnuLinux * getGnuLinux();
        void createNewGnuLinux();
        virtual void buildEnvironmentDesktop() = 0;
        virtual void buildWindowManager() = 0;
        virtual void buildShell() = 0;
    protected:
        GnuLinux * gnuLinux;
};

GnuLinux * GnuLinuxBuilder::getGnuLinux() {
    return gnuLinux;
}

void GnuLinuxBuilder::createNewGnuLinux() {
    gnuLinux = new GnuLinux();
    buildEnvironmentDesktop();
    buildWindowManager();
    buildShell();
}

#endif
