//
// Created by tuurm on 25/06/2023.
//

#include <cstdlib>
#include "utils.h"

double RandomDouble() {
    return rand() / (RAND_MAX + 1.0);
}

double RandomDouble(double min, double max) {
    return min + (max - min) * RandomDouble();
}