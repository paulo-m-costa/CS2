/**
 * @file debugging1.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2014-2015
 * @copyright This code is in the public domain.
 *
 * @brief An example of the utility of print statements in debugging.
 */

/*
 * For each iteration of the while loop, the parity of b is checked.
 * If b is odd, a is added to x. Then a is bitshifted left (multiplyied by 2) and 
 * b is bitshifted right (divided by 2). This is repeated until b is 0.
 * x ends up being 14790, or the product of the given a and b.
 * If you change a and b you will likely end up with a different final x and a.
 * However, x will still be the product of the initial a and b.
 * This works by adding multiples of a of the form a * 2^n until b is "drained" to 0.
 */

#include <iostream>

using namespace std;

/**
 * @brief Does a thing.
 *
 * Does a thing, I dunno, you tell me.
 */
int main(int argc, char ** argv)
{
    // Much of the following is intentionally undocumented.
    // Part of the assignment is to figure out what is going on.
    // You may need to look up some operators!
    unsigned int a = 174, b = 85, x = 0;
    cout << "Initial values: a: " << a << ", b: " << b << ", x: " << x << endl;

    // This construct is known as a 'while loop'.
    // The interior of the loop is run if, and while,
    // the given condition is true.
    // The program proceeds past the loop if, and when,
    // the given condition is found to be false just before any iteration
    // of the interior of the loop.
    while (b != 0)
    {
        // This construct is known as a conditional statement
        // ('if' statement).
        // The interior of the statement is run exactly once in its entirety
        // if the given condition is found to be true.
        // Note that 'true' is defined as nonzero,
        // and 'false' is defined as zero.
        if ((b & 1) != 0)
        {
            x += a;
	    cout << "In if statement: b: " << b << ", x: " << x << endl;
        }
        a <<= 1;
        b >>= 1;
	cout << "In while loop: a: " << a << ", b: " << b << ", x: " << x << endl;
    }
    cout << "Final values: a: " << a << ", b: " << b << ", x: " << x << endl;

    // Question for you now: so what is x anyway?

    return 0;
}