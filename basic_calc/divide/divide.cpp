#include "basic_calc/divide/divide.h"
double divide(double a, double b) {
    if (b == 0) return 0; // simple handling
    return a / b;
}
