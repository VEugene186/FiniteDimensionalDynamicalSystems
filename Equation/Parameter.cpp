#include "Parameter.h"
#include <cstdlib>
#include <cstdio>

Parameter::Parameter(const char * name, double * p) : name_(name), p_(p) {
    if (p_ == nullptr) {
        fprintf(stderr, "Parameter \'%s\' contains null pointer\n", name_.c_str());
        exit(1);
    }
}

Parameter::~Parameter() {

}

double Parameter::getValue() const {
    return *p_;
}

void Parameter::setValue(double val) {
    *p_ = val;
}

const std::string & Parameter::getName() const {
    return name_;
}
