//Абстрактный класс, описывающий систему ОДУ первого порядка
//разрешенных отноистельно производных.
#ifndef EQUATION_H_
#define EQUATION_H_

#include "Parameter.h"
#include "PhaseVariable.h"
#include <vector>

class Equation {
public:
    Equation();
    virtual ~Equation();

    void addParameter(const char * name, double * p);
    Parameter * findParameter(const char * name);

    void addPhaseVariable(const char * name, double periodicity = false, double leftLimit = -1e16, double rightLimit = 1e16);
    const PhaseVariable * findPhaseVariable(const char * name) const;
protected:
    int dim_;
    std::vector<Parameter*> parameters_;
    std::vector<PhaseVariable*> variables_;
};


#endif
