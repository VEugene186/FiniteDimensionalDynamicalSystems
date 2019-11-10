#include "Equation.h"
#include <cstdlib>
#include <cstdio>

Equation::Equation() {

}

Equation::~Equation() {

}

void Equation::addParameter(const char * name, double * p) {
    if (findParameter(name) != nullptr) {
        fprintf(stderr, "Parameter \'%s\' exists already\n", name);
    }
    parameters_.push_back(new Parameter(name, p));
}

Parameter * Equation::findParameter(const char * name) {
    for (int i = 0; i < (int)parameters_.size(); i++) {
        if (parameters_[i]->getName() == name) return parameters_[i];
    }
    return nullptr;
}

void Equation::addPhaseVariable(const char * name, double periodicity/* = false*/, double leftLimit/* = -1e16*/, double rightLimit/* = 1e16*/) {
    if (findPhaseVariable(name) != nullptr) {
        fprintf(stderr, "Phase variable \'%s\' exists already\n", name);
    }
    variables_.push_back(new PhaseVariable(name, periodicity, leftLimit, rightLimit));

}

const PhaseVariable * Equation::findPhaseVariable(const char * name) const {
    for (int i = 0; i < (int)variables_.size(); i++) {
        if (variables_[i]->getName() == name) return variables_[i];
    }
    return nullptr;

}
