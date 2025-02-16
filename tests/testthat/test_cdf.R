testthat::test_that("CDF evaluation", {
    x = cdfdistances::cdf_obs(c(1,2,3,4))
    testthat::expect_equal(x$eval(0), 0)
    testthat::expect_equal(x$eval(1), 0.25)
    testthat::expect_equal(x$eval(2), 0.5)
    testthat::expect_equal(x$eval(3), 0.75)
    testthat::expect_equal(x$eval(4), 1)
})

testthat::test_that("Wasserstein", {
    x = cdfdistances::cdf_obs(c(1,2,3))
    y = cdfdistances::cdf_obs(c(1.5,2.5,3.5))
    testthat::expect_equal(cdfdistances::wasserstein(x$cdf, y$cdf), 0.5)

    x = cdfdistances::cdf_obs(c(1.0, 1.0, 2.0, 2.0, 3.0))
    y = cdfdistances::cdf_obs(c(1.5, 2.5, 2.5, 3.5))
    testthat::expect_equal(cdfdistances::wasserstein(x$cdf, y$cdf), 0.7)
})
