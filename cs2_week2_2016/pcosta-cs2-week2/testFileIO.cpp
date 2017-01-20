/**
 * @file testFileIO.cpp
 * @author The CS2 TA Team <<cs2tas@caltech.edu>>
 * @version 1.0
 * @date 2013-2015
 * @copyright This code is in the public domain.
 *
 * @brief A brief example of file input.
 */

#include "fileio.h"

/**
 * @brief Read the file input and print out its contents
 *
 * Assumes that the file contains one integer per line.
 */


int main(int argc, char const *argv[])
{
    // TODO Write test code to instantiate a vector, then calls the readFile and
    // print_vector functions to demonstrat that the file was read successfully.

    const char* filename = argv[1];
    vector <int> num;
    readFile(filename,num);
    print_vector(num);
}
