#include "cdfdistances_types.h"
#include <Rcpp.h>
#include <numeric>

using Rcpp::NumericVector;
using Rcpp::Rcout;
using Rcpp::XPtr;

using std::endl;

//' cdf_from_obs
//'
//' Create an empirical CDF from observations
//' @param obs A numeric vector of observations
//' @return An XPtr to an EmpiricalCDF object
// [[Rcpp::export]]
XPtr<EmpiricalCDF> cdf_from_obs(NumericVector obs) {
    size_t n = obs.size();
    EmpiricalCDF* cdf = new EmpiricalCDF{
        vector<double>(obs.begin(), obs.end()),
        vector<double>(n)
    };
    std::sort(cdf->breaks.begin(), cdf->breaks.end());
    std::iota(cdf->values.begin(), cdf->values.end(), 1.0);
    std::transform(cdf->values.begin(), cdf->values.end(), cdf->values.begin(), [&](double x){ return x / n;});
    return XPtr<EmpiricalCDF>(cdf);
}

//' cdf_from_timing
//'
//' Create an empirical CDF from timings and dosages
//' @param t A numeric vector of timings
//' @param obs A numeric vector of dosages
// [[Rcpp::export]]
XPtr<EmpiricalCDF> cdf_from_timing(NumericVector t, NumericVector obs) {
    size_t n = obs.size();
    double total = std::reduce(obs.begin(), obs.end());
    vector<size_t> indices(n);
    std::iota(indices.begin(), indices.end(), 0);
    std::sort(indices.begin(), indices.end(), [&](size_t i, size_t j){ return t[i] < t[j]; });

    EmpiricalCDF* cdf = new EmpiricalCDF{
        vector<double>(n),
        vector<double>(n)
    };

    std::transform(indices.begin(), indices.end(), cdf->breaks.begin(), [&](size_t i){ return t[i]; });
    double current = 0;
    std::transform(indices.begin(), indices.end(), cdf->values.begin(), [&](size_t i) {
        current += obs[i];
        return current / total;
    });

    return XPtr<EmpiricalCDF>(cdf);
}

//' eval_cdf
//'
//' Evaluate the CDF at a given point
//' @param cdf An XPtr to an EmpiricalCDF object
//' @param x The point at which to evaluate the CDF
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
