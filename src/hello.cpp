#include <string>
#include <Rcpp.h>
using namespace Rcpp;

//' @export
// [[Rcpp::export]]
XPtr<std::string> hello_cpp() {
    return XPtr<std::string>(new std::string("Hello from C++, world!"));
}

//' @export
// [[Rcpp::export]]
String evaluate(XPtr<std::string> x) {
    return *x;
}
