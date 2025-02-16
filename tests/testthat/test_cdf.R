testthat::test_that("CDF evaluation", {
    x = cdfdistances::cdf_obs(c(1,2,3,4))
    testthat::expect_equal(x$eval(0), 0)
    testthat::expect_equal(x$eval(1), 0.25)
    testthat::expect_equal(x$eval(2), 0.5)
    testthat::expect_equal(x$eval(3), 0.75)
    testthat::expect_equal(x$eval(4), 1)
})
