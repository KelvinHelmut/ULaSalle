/*
 * =============================================================================
 *
 *       Filename:  gnulinux.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 23:34:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#include "gnulinux.h"

void GnuLinux::setEnvironmentDesktop(string environmentDesktop) {
    this->environmentDesktop = environmentDesktop;
}

void GnuLinux::setWindowManager(string windowManager) {
    this->windowManager = windowManager;
}

void GnuLinux::setShell(string shell) {
    this->shell = shell;
}

void GnuLinux::info() {
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Enviroment Desktop: " << this->environmentDesktop << std::endl;
    std::cout << "Window Manager: " << this->windowManager << std::endl;
    std::cout << "Shell: " << this->shell << std::endl;
    std::cout << "-------------------------------------" << std::endl;
}
