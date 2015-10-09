#ifndef NODE
#define NODE

#include <ostream>

template<class T>
class Node {
public:
    virtual T getValue() = 0;
    virtual Node<T>*& getLink(int) = 0;
    virtual void setLink(Node<T>*, int) = 0;
};

#endif // NODE

