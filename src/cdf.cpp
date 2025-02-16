#include "cdfdistances_types.h"
#include <Rcpp.h>
#include <numeric>

using Rcpp::NumericVector;
using Rcpp::Rcout;
using Rcpp::XPtr;

using std::endl;

// [[Rcpp::export]]
XPtr<EmpiricalCDF> cdf_from_obs(NumericVector obs) {
    size_t n = obs.size();
    auto sorted_obs = obs.sort();
    EmpiricalCDF* cdf = new EmpiricalCDF;
    cdf->breaks = vector<double>(sorted_obs.begin(), sorted_obs.end());
    cdf->values.resize(obs.size());
    std::iota(cdf->values.begin(), cdf->values.end(), 1.0);
    std::transform(cdf->values.begin(), cdf->values.end(), cdf->values.begin(), [&](double x){ return x / n;});
    return XPtr<EmpiricalCDF>(cdf);
}

// [[Rcpp::export]]
XPtr<EmpiricalCDF> cdf_from_timing(NumericVector t, NumericVector obs) {
    EmpiricalCDF* cdf = new EmpiricalCDF;
    return XPtr<EmpiricalCDF>(cdf);
}

// [[Rcpp::export]]
double eval_cdf(XPtr<EmpiricalCDF> cdf, double x) {
    // Binary search
    size_t lower = 0;
    size_t upper = cdf->breaks.size();

    // Find
    while (lower < upper) {
        size_t mid = (lower + upper) / 2;
        if (cdf->breaks[mid] > x) {
            upper = mid;
        } else {
            lower = mid + 1;
        }
    }

    if (lower == 0) {
        return 0.0;
    } else {
        return cdf->values[lower-1];
    }
}

// [[Rcpp::export]]
double wasserstein(XPtr<EmpiricalCDF> cdf1, XPtr<EmpiricalCDF> cdf2) {
    return 0.0;
}


// [[Rcpp::export]]
double ks(XPtr<EmpiricalCDF> cdf1, XPtr<EmpiricalCDF> cdf2) {
    return 0.0;
}
