/*
 * =============================================================================
 *
 *       Filename:  singleobject.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  18/10/15 22:40:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kelvin Helmut Provincia Quispe (), aek6.io@gmail.com
 *   Organization:  
 *
 * =============================================================================
 */

#ifndef SINGLEOBJECT_H
#define SINGLEOBJECT_H

class SingleObject {
    public:
        static SingleObject * getInstance();
    private:
        SingleObject() {}
        static SingleObject * instance;
};

SingleObject * SingleObject::instance = 0;

SingleObject * SingleObject::getInstance() {
    if (!instance) instance = new SingleObject();
    return instance;
}

#endif
