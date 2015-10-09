#ifndef TREE
#define TREE

#include "linkedstructure.h"

template<class T>
class Tree : public LinkedStructure<T> {
public:
    virtual void add(T) = 0;
    virtual void show(std::ostream&) = 0;
    virtual void dot(char* file) = 0;
};

#endif // TREE

