#include "ClassicRungeKuttaMethod.h"

ClassicRungeKuttaMethod::ClassicRungeKuttaMethod(int dim) : ExplicitRungeKuttaMethod(4, dim) {
    init();
}

ClassicRungeKuttaMethod::~ClassicRungeKuttaMethod() {

}

void ClassicRungeKuttaMethod::init() {
    C_[0] = 0.0; A_[0][0] = 0.0; A_[0][1] = 0.0; A_[0][2] = 0.0; A_[0][3] = 0.0;
    C_[1] = 0.5; A_[1][0] = 0.5; A_[1][1] = 0.0; A_[1][2] = 0.0; A_[1][3] = 0.0;
    C_[2] = 0.5; A_[2][0] = 0.0; A_[2][1] = 0.5; A_[2][2] = 0.0; A_[2][3] = 0.0;
    C_[3] = 1.0; A_[3][0] = 0.0; A_[3][1] = 0.0; A_[3][2] = 1.0; A_[3][3] = 0.0;
    B_[0] = 1.0 / 6.0;
    B_[1] = 1.0 / 3.0;
    B_[2] = 1.0 / 3.0;
    B_[3] = 1.0 / 6.0;
    hatB_[0] = 1.0 / 6.0;
    hatB_[1] = 1.0 / 3.0;
    hatB_[2] = 1.0 / 3.0;
    hatB_[3] = 1.0 / 6.0;
}
