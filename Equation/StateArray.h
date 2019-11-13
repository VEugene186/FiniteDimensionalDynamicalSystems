#ifndef STATEARRAY_H
#define STATEARRAY_H

#include <vector>
#include "StateVector.h"

class StateArray {
public:
    StateArray(int dim);
    ~StateArray();

    int getDim() const;
    int getLength() const;
    StateVector * operator[](int n);
    const StateVector * operator[](int n) const;
    StateVector * getNew();
    StateVector * getLast();
    const StateVector * getLast() const;
private:
    int dim_;
    std::vector<StateVector*> data_;
};

#endif
