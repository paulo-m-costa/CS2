/**
 * @file pointers3.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2015
 * @copyright This code is in the public domain.
 *
 * @brief Pointer-fu Exercise 3: "Entangled" pointers
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/**
 * @brief Set two pointers to the same memory and free them.
 */
int main(int argc, char *argv[])
{
    int *a, *b;

    // Allocate an array of 10 ints.
    a = (int *) malloc(10 * sizeof(int));

    // Now `b` points to the same array of ints.
    *b = *a;

/* I changed the line "b = a" to "*b = *a" because originally b would just be
 * set to whatever value a was initialized as rather than the memory it was 
 * pointing to. Now b points to the memory a is pointing to as desired.
 */

    free(a);
    free(b);

    return 0;
}
