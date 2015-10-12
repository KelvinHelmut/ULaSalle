#ifndef INTERVAL
#define INTERVAL

template<class T>
class Interval {
public:
    Interval(T low, T high);
    //Interval(Interval<T> &);
    T getLow();
    T getHigh();
    void setLow(T);
    void setHigh(T);

    bool operator ==(Interval<T> &interval);
    bool operator <(Interval<T> &interval);

private:
    T values[2];
};

template<class T>
Interval<T>::Interval(T low, T high) {
    setLow(low);
    setHigh(high);
}
/*
template<class T>
Interval<T>::Interval(Interval<T> &interval) {
    setLow(interval.getLow());
    setHigh(interval.getHigh());
}*/

template<class T>
T Interval<T>::getLow() {
    return values[0];
}

template<class T>
T Interval<T>::getHigh() {
    return values[1];
}

template<class T>
void Interval<T>::setLow(T low) {
    values[0] = low;
}

template<class T>
void Interval<T>::setHigh(T high) {
    values[1] = high;
}

template<class T>
bool Interval<T>::operator ==(Interval<T> &interval) {
    std::cout <<" == " <<std::endl;
    return getLow() == interval->getLow() && getHigh() == interval->getHigh();
}

template<class T>
bool Interval<T>::operator <(Interval<T> &interval) {
    std::cout <<" < " <<std::endl;
    return getLow() < interval->getLow();
}

#endif // INTERVAL

