#ifndef PHASEVARIABLE_H
#define PHASEVARIABLE_H

#include <string>

class PhaseVariable {
public:
    PhaseVariable(const char * name, bool periodicity = false, double leftLimit = -1e16, double rightLimit = 1e16);
    ~PhaseVariable();

    const std::string & getName() const;
    bool getPeriodicity() const;
    double getLeftLimit() const;
    double getRightLimit() const;
private:
    std::string name_;
    bool periodicity_;
    double leftLimit_, rightLimit_;
};

#endif
