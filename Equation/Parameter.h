#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>

class Parameter {
public:
    Parameter(const char * name, double * p);
    virtual ~Parameter();

    double getValue() const;
    void setValue(double val);
    const std::string & getName() const;
protected:
    std::string name_;
    double * p_;
};

#endif
