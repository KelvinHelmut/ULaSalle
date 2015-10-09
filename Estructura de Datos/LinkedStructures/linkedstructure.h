#ifndef LINKEDSTRUCTURE
#define LINKEDSTRUCTURE

#include <ostream>

template<class T>
class LinkedStructure {
    virtual void add(T) = 0;
    virtual void show(std::ostream &) = 0;
    virtual void dot(char* file) = 0;
};

#endif // LINKEDSTRUCTURE

