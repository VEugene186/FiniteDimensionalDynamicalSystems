#include "ExplicitRungeKuttaMethod.h"

ExplicitRungeKuttaMethod::ExplicitRungeKuttaMethod(int nStages, int dim) : RungeKuttaMethod(nStages, dim) {

}

ExplicitRungeKuttaMethod::~ExplicitRungeKuttaMethod() {

}

bool ExplicitRungeKuttaMethod::makeStep(const Equation & eqs, const StateVector & q0, StateVector & q1, double step) {
    double sum;
    for (int n = 0; n < nStages_; n++) {
        for (int i = 0; i < dim_; i++) {
            sum = 0.0;
            for (int j = 0; j < n - 1; j++) {
                sum += A_[n][j] * (*k_[j])[i];
            }
            (*tmpQ_[n])[i] = q0[i] + step * sum;
        }
        
        if (!eqs.rhs(*tmpQ_[n], *k_[n])) return false;
    }
    for (int i = 0; i < dim_; i++) {
        sum = 0.0;
        for (int j = 0; j < n - 1; j++) {
            sum += B_[j] * (*k_[j])[i];
        }
        q1[i] = q0[i] + step * sum;
    }   
    return true;  
}
