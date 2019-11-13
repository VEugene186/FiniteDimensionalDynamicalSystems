#include "StateArray.h"


StateArray::StateArray(int dim) : dim_(dim) {

}

StateArray::~StateArray() {
    for (int n = 0; n < (int)data_.size(); n++) {
        delete data_[n];
    }
}

int StateArray::getDim() const {
    return dim_;
}
 
int StateArray::getLength() const {
    return (int)data_.size();
}

StateVector * StateArray::operator[](int n) {
    return data_[n];
}
 
const StateVector * StateArray::operator[](int n) const {
    return data_[n];
}
 
StateVector * StateArray::getNew() {
    data_.push_back(new StateVector(dim_));
    return data_.back();
}
 
StateVector * StateArray::getLast() {
    return data_.back();
}

const StateVector * StateArray::getLast() const {
    return data_.back();
}
