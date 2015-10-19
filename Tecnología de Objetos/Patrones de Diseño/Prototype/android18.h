/*
 * =============================================================================
 *
 *       Filename:  android18.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/10/15 01:26:54
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef ANDROID18_H
#define ANDROID18_H

#include "androidclone.h"

class Android18 : public AndroidClone {
    public:
        Android18(int power) {
            this->name = "Android 18";
            this->power = power;
        }
        AndroidClone * clone() {
            return new Android18(*this);
        }
};

#endif
