#include "PhaseVariable.h"

PhaseVariable::PhaseVariable(const char * name, bool periodicity/* = false*/, double leftLimit/* = -1e16*/, double rightLimit/* = 1e16*/) :
        name_(name), periodicity_(periodicity), leftLimit_(leftLimit), rightLimit_(rightLimit) {

}

PhaseVariable::~PhaseVariable() {

}

const std::string & PhaseVariable::getName() const {
    return name_;
}

bool PhaseVariable::getPeriodicity() const {
    return periodicity_;
}

double PhaseVariable::getLeftLimit() const {
    return leftLimit_;
}

double PhaseVariable::getRightLimit() const {
    return rightLimit_;
}
