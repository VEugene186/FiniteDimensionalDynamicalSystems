#ifndef CLASSICRUNGEKUTTAMETHOD_H
#define CLASSICRUNGEKUTTAMETHOD_H

#include "ExplicitRungeKuttaMethod.h"

class ClassicRungeKuttaMethod : public ExplicitRungeKuttaMethod {
public:
    ClassicRungeKuttaMethod(int dim);
    ~ClassicRungeKuttaMethod();
private:
    void init();
};

#endif
