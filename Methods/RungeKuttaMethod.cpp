#include "RungeKuttaMethod.h"
#include <cstdlib>
#include <cstdio>
#include <cmath>

RungeKuttaMethod::RungeKuttaMethod(int nStages, int dim) {
    allocate(nStages, dim);
}

RungeKuttaMethod::~RungeKuttaMethod() {
    free();
}

void RungeKuttaMethod::check() const {
    const double tol = 1e-14;
    double sum = 0.0;
    //check B
    for (int n = 0; n < nStages_; n++) {
        sum += B_[n];
    }
    if (fabs(sum - 1.0) > tol) {
        fprintf(stderr, "Error in B coefficients\n");
        exit(1);
    }
    //check hatB
    sum = 0.0;
    for (int n = 0; n < nStages_; n++) {
        sum += hatB_[n];
    }
    if (fabs(sum - 1.0) > tol) {
        fprintf(stderr, "Error in hatB coefficients\n");
        exit(1);
    }
    //check A and C
    for (int n = 0; n < nStages_; n++) {
        sum = 0.0;
        for (int j = 0; j < nStages_; j++) {
            sum += A_[n][j];
        }
        if (fabs(sum - C_[n]) > tol) {
            fprintf(stderr, "Error in A or C coefficients at stage %d\n", n);
            exit(1);
        }
    }
}

void RungeKuttaMethod::allocate(int nStages, int dim) {
    nStages_ = nStages;
    dim_ = dim;
    A_ = new double*[nStages_];
    B_ = new double[nStages_];
    hatB_ = new double[nStages_];
    C_ = new double[nStages_];
    k_.resize(nStages_);
    tmpQ_.resize(nStages_);
    for (int i = 0; i < nStages_; i++) {
        A_[i] = new double[nStages_];
        k_[i] = new StateVector(dim_);
        tmpQ_[i] = new StateVector(dim_);
    }
}

void RungeKuttaMethod::free() {
    for (int i = 0; i < nStages_; i++) {
        delete [] A_[i];
        delete k_[i];
        delete tmpQ_[i];
    }
    delete [] A_;
    delete [] B_;
    delete [] hatB_;
}
