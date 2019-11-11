#ifndef EXPLICITRUNGEKUTTAMETHOD_H
#define EXPLICITRUNGEKUTTAMETHOD_H

#include "RungeKuttaMethod.h"

class ExplicitRungeKuttaMethod : public RungeKuttaMethod {
public:
    ExplicitRungeKuttaMethod(int nStages, int dim);
    virtual ~ExplicitRungeKuttaMethod();

    bool makeStep(const Equation & eqs, const StateVector & q0, StateVector & q1, double step);

protected:
};


#endif
