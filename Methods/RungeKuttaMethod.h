//Абстрактный класс, определяющий интерфейс метод Рунге-Кутты

#ifndef RUNGEKUTTAMETHOD_H
#define RUNGEKUTTAMETHOD_H

#include "Method.h"

class RungeKuttaMethod : public Method {
public:
    RungeKuttaMethod(int nStages, int dim);
    virtual ~RungeKuttaMethod();
    
    void check() const;
private:
    void allocate(int nStages, int dim);
    void free();
protected:
    int nStages_, dim_;
    double **A_, *B_, *hatB_, *C_;
    std::vector<StateVector*> k_, tmpQ_;
};

#endif
