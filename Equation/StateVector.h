#ifndef STATEVECTOR_H
#define STATEVECTOR_H

class StateVector {
public:
    StateVector(int dim);
    ~StateVector();

    double t() const;
    double & t();
    double & operator[](int n);
    double operator[](int n) const;
    StateVector & operator=(const StateVector & orig);
private:
    int dim_;
    double t_;
    double *data_;
};

#endif
