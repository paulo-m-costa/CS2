#include <stdio.h>
#include <math.h>

/**
 * @brief Solves the given quadratic equation.
 *
 * This function, given real coefficients A, B, C to the equation
 * A*x*x + B*x + C = 0, returns the real part of a solution to the
 * equation thus defined. Where two real solutions exist, the one
 * closer to positive infinity is chosen.
 *
 * @param a the quadratic coefficient.
 * @param b the linear coefficient.
 * @param c the constant coefficient.
 *
 * @return the real part of a solution to the defined quadratic equation,
 *         as described.
 */
double qfsolve(double a, double b, double c)
{
    // Return only the real part if discriminant is negative.
    if ((pow(b, 2) - 4 * a * c) < 0)
        return -b / (2 * a);
    // Return the real solution closer to positive infinity.
    return (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
}

/**
 * @Tests the qfsolve function.
 */
int main(int argc, char ** argv)
{
    printf("Input: 1, 2, 3. Output: %g\n", qfsolve(1, 2, 3));
    printf("Input: 1, 4, -9. Output: %g\n", qfsolve(1, 4, -9));
    printf("Input: 1, 8, -27. Output: %g\n", qfsolve(1, 8, -27));
    printf("Input: 2, 4, -8. Output: %g\n", qfsolve(2, 4, -8));
    printf("Input: 21, 69, -420. Output: %g\n", qfsolve(21, 69, -420));
    return 0;
}
