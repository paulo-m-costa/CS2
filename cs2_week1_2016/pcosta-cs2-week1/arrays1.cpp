/**
 * @file arrays1.cpp
 * @author The CS2 TA Team <cs2tas@caltech.edu>
 * @date 2014-2015
 * @copyright This code is in the public domain.
 *
 * @brief An array example.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

#define TEST_SIZE 60

using namespace std;

/**
 * @brief: Finds the maximum value of an array of integers.
 *
 * @param arr[]: The array.
 * @param length: The length of the array.
 *
 * @return: The max of the array.
 */
int findArrayMax(int arr[], int length)
{
    int max = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

/**
 * @brief Finds the arithmetic mean of an array of integers.
 *
 * @param arr[]: The array.
 * @param length: the length of the array.
 *
 * @return: The mean of the array.
 */
double findArrayMean(int arr[], int length)
{
    double sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += arr[i];
    }
    return sum / length;
}

/**
 * @brief Fill an array of integers with an ascending sequence.
 *
 * @param arr[]: The array.
 * @param length: The length of the array.
 * @param sequence_start: The number which will start the ascending sequence.
 *
 * @return: Void.
 */
void fillArrayAscending(int arr[], int length, int sequence_start)
{
    for (int i = 0; i < length; i++)
    {
        arr[i] = sequence_start;
        sequence_start++;
    }
}

/**
 * @brief Sets up and runs an array example.
 */
int main(int argc, char ** argv)
{

    /*-------- CHANGE NOTHING BELOW THIS LINE FOR PART 1 --------*/
    int test_values[TEST_SIZE];
    int real_size;

    // seed the PRNG
    srand(time(nullptr));

    // initialize the test array to garbage
    for (int i = 0; i < TEST_SIZE; i++)
    {
        test_values[i] = rand();
    }

    // determine a real size
    real_size = TEST_SIZE - (rand() % 20);

    // initialize the meaningful part of the test array to random numbers
    // all of which are less than one million
    for (int i = 0; i < real_size; i++)
    {
        test_values[i] = rand() % 1000000;
    }
    /*-------- CHANGE NOTHING ABOVE THIS LINE FOR PART 1 --------*/

    int arr[3] = {1, 2, 3};
    int max = findArrayMax(arr, 3);
    int mean = findArrayMean(arr, 3);
    fillArrayAscending(arr, 3, 5);
    cout << "Max: " << max << ", Mean: " << mean << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Index " << i << ": " << arr[i] <<endl;
    }
}