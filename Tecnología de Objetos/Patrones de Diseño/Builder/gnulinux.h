/*
 * =============================================================================
 *
 *       Filename:  gnulinux.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 23:30:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef GNULINUX_H
#define GNULINUX_H

#include <string>
#include <iostream>

using std::string;

class GnuLinux {
    public:
        void setEnvironmentDesktop(string);
        void setWindowManager(string);
        void setShell(string);
        void info();
    private:
        string windowManager;
        string environmentDesktop;
        string shell;
};

#endif
