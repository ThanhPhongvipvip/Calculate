#include <iostream>
#include "basic_calc/add/add.h"
#include "basic_calc/subtract/subtract.h"
#include "basic_calc/multiply/multiply.h"
#include "basic_calc/divide/divide.h"
#include "advance_calc/power/power_op.h"
#include "advance_calc/sqrt/sqrt_op.h"

int main() {
    double a = 8;
    double b = 6;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << add(a, b) << std::endl;
    std::cout << "a - b = " << subtract(a, b) << std::endl;
    std::cout << "a * b = " << multiply(a, b) << std::endl;
    std::cout << "a / b = " << divide(a, b) << std::endl;
    std::cout << "a ^ b = " << power(a, b) << std::endl;
    std::cout << "sqrt(a) = " << square_root(a) << std::endl;

    return 0;
}
