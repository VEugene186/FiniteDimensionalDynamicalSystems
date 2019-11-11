//Абстрактный класс, определяющий интерфейс методов интегрирования
//От него будут унаследованы методы Рунге-Кутты и методы Адамса

#ifndef METHOD_H
#define METHOD_H

#include "../Equation/StateVector.h"
#include "../Equation/Equation.h"

class Method {
public:
    Method();
    virtual ~Method();

    virtual bool makeStep(const Equation & eqs, const StateVector & q0, StateVector & q1) = 0;
};

#endif
