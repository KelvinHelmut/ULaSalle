#ifndef NODEINTERVAL
#define NODEINTERVAL

#include "noderb.h"
#include "interval.h"

template<class T>
class NodeInterval : public NodeRB<Interval<T>*> {
public:
    NodeInterval(Interval<T>* value);
    T getMax();
    void setMax(T);

private:
    T max;
};

template<class T>
NodeInterval<T>::NodeInterval(Interval<T>* value) {
    this->value = value;
    max = this->value->getHigh();
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

