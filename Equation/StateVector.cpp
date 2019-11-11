#include "StateVector.h"
#include <cstdlib>
#include <cstdio>

StateVector::StateVector(int dim) {
    if (dim < 1) {
        fprintf(stderr, "Dimension of State Vector should be positive\n");
        exit(1);
    }
    dim_ = dim;
    t_ = 0.0;
    data_ = new double[dim_];
}

StateVector::~StateVector() {
    delete [] data_;
}

double StateVector::t() const {
    return t_;
}

double & StateVector::t() {
    return t_;
}

double StateVector::operator[](int n) const {
    return data_[n];
}

double & StateVector::operator[](int n) {
    return data_[n];
}

StateVector & StateVector::operator=(const StateVector & orig) {
    t_ = orig.t_;
    for (int i = 0; i < dim_; i++) {
        data_[i] = orig.data_[i];
    }
    return *this;
}
