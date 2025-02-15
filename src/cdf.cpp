#include "cdfdistances_types.h"
#include <Rcpp.h>

using Rcpp::NumericVector;
using Rcpp::XPtr;

// [[Rcpp::export]]
XPtr<EmpiricalCDF> cdf_from_obs(NumericVector obs) {
    auto sorted_obs = obs.sort();
    EmpiricalCDF* cdf = new EmpiricalCDF;
    return XPtr<EmpiricalCDF>(cdf);
}

// [[Rcpp::export]]
XPtr<EmpiricalCDF> cdf_from_timing(NumericVector t, NumericVector obs) {
    EmpiricalCDF* cdf = new EmpiricalCDF;
    return XPtr<EmpiricalCDF>(cdf);
}

// [[Rcpp::export]]
double eval_cdf(XPtr<EmpiricalCDF> cdf, double x) {
    return 0.0;
}

// [[Rcpp::export]]
double wasserstein(XPtr<EmpiricalCDF> cdf1, XPtr<EmpiricalCDF> cdf2) {
    return 0.0;
}
