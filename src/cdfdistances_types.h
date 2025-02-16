#ifndef CDF_H
#define CDF_H

#include <vector>
using std::vector;

struct EmpiricalCDF {
    vector<double> breaks;
    vector<double> values;
};

#endif
