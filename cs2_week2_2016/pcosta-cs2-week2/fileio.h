/**
 * @file fileio.h
 * @author The CS2 TA Team <<cs2tas@caltech.edu>>
 * @version 1.0
 * @date 2013-2015
 * @copyright This code is in the public domain.
 *
 * @brief A brief example of file input (headers).
 *
 */

#ifndef __FILEIO_H__
#define __FILEIO_H__

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void readFile(char const *file, std::vector<int> &nums);

/**
 * @brief Prints the contents of a vector to stdout, delimited by newlines.
 *
 * @param v: vector to be printed
 */
inline void print_vector(std::vector<int> v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
    	cout << v[i] << endl;
    }
}

#endif