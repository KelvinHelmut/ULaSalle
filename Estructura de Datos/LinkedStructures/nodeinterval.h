#ifndef NODEINTERVAL
#define NODEINTERVAL

#include "node.h"
#include "interval.h"

template<class T>
class NodeInterval : public Node<Interval<T>*> {
public:
    NodeInterval(Interval<T>* value);
    Interval<T>* getValue();
    Node<Interval<T>*>*& getLink(int);
    void setLink(Node<Interval<T>*>*, int) {}
    T getMax();
    void setMax(T);

private:
    Interval<T> *value;
    T max;
    Node<Interval<T>*> *links[2];
};

template<class T>
NodeInterval<T>::NodeInterval(Interval<T>* value) {
    this->value = value;
    max = value->getHigh();
    links[0] = links[1] = 0;
}

template<class T>
Interval<T>* NodeInterval<T>::getValue() {
    return value;
}

template<class T>
Node<Interval<T>*>*& NodeInterval<T>::getLink(int i) {
    return links[i];
}

template<class T>
T NodeInterval<T>::getMax() {
    return max;
}

template<class T>
void NodeInterval<T>::setMax(T max) {
    this->max = max;
}

#endif // NODEINTERVAL

