/*
 * =============================================================================
 *
 *       Filename:  androidclone.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/10/15 01:15:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef ANDROIDCLONE_H
#define ANDROIDCLONE_H

#include <string>

using std::string;

class AndroidClone {
    public:
        virtual AndroidClone * clone() = 0;
        string getName() { return name; }
        int getPower() { return power; }
    protected:
        string name;
        int power;
};

#endif
