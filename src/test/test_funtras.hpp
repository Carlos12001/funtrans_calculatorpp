//
// Created by carlo on 3/4/2023.
//

#ifndef FUNTRANS_CALCULATORPP_TEST_HPP
#define FUNTRANS_CALCULATORPP_TEST_HPP
#include "../header.hpp"
#include "../funtrans/funtrans.hpp"

/**
 * A class that provides methods for testing various functions in the `funtrans`
 * namespace.
 *
 * This class includes methods for testing various functions in the `funtrans`
 * namespace, including
 * `test_funtras` and `all`. The `test_funtras` method tests a specific set of
 * functions and returns
 * the result as a `decimal_50_digits` object, while the `all` method tests a
 * larger set of functions
 * and outputs the results to the console.
 *
 * Note that the class relies heavily on the `funtrans` namespace, which
 * contains implementations
 * of various mathematical functions.
 *
 * @see funtrans
 */
class Test {

public:

    /**
     * Constructs a new `Test` object.
     *
     * This constructor does not take any arguments and simply
     * outputs a header to the console to
     * indicate that a new test is beginning.
     */
    Test();

    /**
     * Tests various functions in the `funtrans` namespace and returns
     * the result as a
     * `decimal_50_digits` object.
     *
     * This method tests various functions in the `funtrans` namespace,
     * including `root_t`, `cos_t`,
     * `divi_t`, `ln_t`, `sinh_t`, `sqrt_t`, and `atan_t`. The result of
     * the tests is returned as a
     * `decimal_50_digits` object.
     *
     * Note that the method uses the `cout` object to print output to
     * the console, and includes calls
     * to various functions from the `funtrans` namespace.
     *
     * @return A `decimal_50_digits` object representing the result of the
     * tests.
     *
     * @see funtrans
     */
    static decimal_50_digits test_funtras();

    /**
     * Tests a larger set of functions in the `funtrans` namespace
     * and outputs the results to the
     * console.
     *
     * This method tests a larger set of functions in the `funtrans`
     * namespace, including `pi_t`,
     * `factorial_t`, `divi_t`, `exp_t`, `sin_t`, `cos_t`, `tan_t`,
     * `ln_t`, `log_t`, `power_t`,
     * `sinh_t`, `cosh_t`, `tanh_t`, `sqrt_t`, `root_t`, `asin_t`,
     * `acos_t`, `atan_t`, `csc_t`,
     * `sec_t`, and `cot_t`. The results of the tests are output
     * to the console using the `cout`
     * object.
     *
     * Note that the method relies heavily on the `funtrans`
     * namespace, which contains implementations
     * of various mathematical functions.
     *
     * @see funtrans
     */
    static void all();

};


#endif //FUNTRANS_CALCULATORPP_TEST_HPP
