# Generated by using Rcpp::compileAttributes() -> do not edit by hand
# Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#' cdf_from_obs
#'
#' Create an empirical CDF from observations
#' @param obs A numeric vector of observations
#' @return An XPtr to an EmpiricalCDF object
cdf_from_obs <- function(obs) {
    .Call(`_cdfdistances_cdf_from_obs`, obs)
}

#' cdf_from_timing
#'
#' Create an empirical CDF from timings and dosages
#' @param t A numeric vector of timings
#' @param obs A numeric vector of dosages
cdf_from_timing <- function(t, obs) {
    .Call(`_cdfdistances_cdf_from_timing`, t, obs)
}

#' eval_cdf
#'
#' Evaluate the CDF at a given point
#' @param cdf An XPtr to an EmpiricalCDF object
#' @param x The point at which to evaluate the CDF
eval_cdf <- function(cdf, x) {
    .Call(`_cdfdistances_eval_cdf`, cdf, x)
}

#' wasserstein
#'
#' Computes the 1-Wasserstein metric between two empirical CDFs
#' @param cdf1 An XPtr to an EmpiricalCDF object
#' @param cdf2 An XPtr to an EmpiricalCDF object
#' @return The 1-Wasserstein distance between the two CDFs
#' @export
wasserstein <- function(cdf1, cdf2) {
    .Call(`_cdfdistances_wasserstein`, cdf1, cdf2)
}

ks <- function(cdf1, cdf2) {
    .Call(`_cdfdistances_ks`, cdf1, cdf2)
}

