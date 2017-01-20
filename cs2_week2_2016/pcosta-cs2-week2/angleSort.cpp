/**
 * @file angleSort.cpp
 * @author The CS2 TA Team <<cs2-tas@ugcs.caltech.edu>>
 * @version 1.0
 * @date 2013-2015
 * @copyright This code is in the public domain.
 *
 * @brief An example of sorting (x, y) pairs by angle.
 *
 */
#include "structs.h"
#include <vector>

using namespace std;

// TODO Modify one of your sorting functions (bubble sort not permitted) and
// implement it here. Add extra arguments as needed.
void quicksort_inplace(vector<Tuple*> &points, vector<double> &list, int left, int right)
{
    int i = left, j = right;
    double temp1, temp2;
    Tuple* temp3 = new Tuple(0, 0);
    Tuple* temp4 = new Tuple(0, 0);
    int pivot = (left + right) / 2;
    while (i <= j)
    {
        while (list[i] < list[pivot])
            {
                i++;
            }
        while (list[j] > list[pivot])
            {
                j--;
            }
        if (i <= j)
            {
                temp1 = list[i];
                temp2 = list[j];
                list[j] = temp1;
                list[i] = temp2;
                temp3 = points[i];
                temp4 = points[j];
                points[i] = temp4;
                points[j] = temp3;
                i++;
                j--;
            }
    }
    if (left < j)
    {
        quicksort_inplace(points, list, left, j);
    }
    if (i < right)
    {
        quicksort_inplace(points, list, i, right);
    }
}

void sort(vector<Tuple*> &points, vector<double> &angles)
{
    quicksort_inplace(points, angles, 0, angles.size() - 1);
    
}

int main(int argc, char const *argv[])
{
    vector<double> angles;
    angles.push_back(4.2);
    angles.push_back(2.8);
    angles.push_back(1.4);
    angles.push_back(5.0);
    angles.push_back(3.3);
    vector<Tuple*> points;
    // Print the initial points and angles
    for (unsigned int i = 0; i < angles.size(); ++i)
    {
        points.push_back(new Tuple(i, i));
    }
    for (vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    {
        (*i)->printTuple();
    }
    for (vector<double>::iterator i = angles.begin(); i != angles.end(); ++i)
    {
        printf("%g\n", *i);
    }

    // Now sort them with respect to angle (points[i] corresponds to angle[i])

    /** THIS IS THE ONLY LINE OF THE MAIN LOOP YOU NEED TO MODIFY. */
    sort(points, angles);
    /** REPLACE THE LINE ABOVE WITH A CALL TO YOUR SORTING FUNCTION. */

    // and print out the new points and angles
    for (vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    {
        (*i)->printTuple();
    }
    for (vector<double>::iterator i = angles.begin(); i != angles.end(); ++i)
    {
        printf("%g\n", *i);
    }

    // Don't want to leak memory...
    // Either of the below implementations works
    // for (std::vector<Tuple*>::iterator i = points.begin(); i != points.end(); ++i)
    // {
    //     delete (*i);
    // }
    for (unsigned int i = 0; i < points.size(); ++i)
    {
        delete points[i];
    }
    return 0;
}