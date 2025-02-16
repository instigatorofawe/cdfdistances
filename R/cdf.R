#' @export
cdf_obs = function(obs) {
    cdf = cdf_from_obs(obs)
    result = list(
        cdf = cdf,
        eval = function(x) eval_cdf(cdf, x)
    )
    result
}

#' @export
cdf_timing = function(t, obs) {
    cdf = cdf_from_timing(t, obs)
    result = list(
        cdf = cdf,
        eval = function(x) eval_cdf(cdf, x)
    )
    result
}
