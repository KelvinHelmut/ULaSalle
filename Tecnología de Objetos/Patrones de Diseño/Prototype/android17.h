/*
 * =============================================================================
 *
 *       Filename:  android17.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  19/10/15 01:23:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef ANDROID17_H
#define ANDROID17_H

#include "androidclone.h"

class Android17 : public AndroidClone {
    public:
        Android17(int power) {
            this->name = "Android 17";
            this->power = power;
        }
        AndroidClone * clone() {
            return new Android17(*this);
        }
};

#endif
