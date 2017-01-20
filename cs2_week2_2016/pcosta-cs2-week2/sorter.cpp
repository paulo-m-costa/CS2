/**
 * @file sorter.cpp
 * @author The CS2 TA Team <<cs2-tas@ugcs.caltech.edu>>
 * @version 1.0
 * @date 2013-2014
 * @copyright This code is in the public domain.
 *
 * @brief The bubble sort, quick sort, merge sort, and in-place quicksort
 * algorithms (implementation).
 *
 */
#include "sorter.h"

using namespace std; 

int main(int argc, char* argv[])
{
    /*Set up buffers and data input*/
    std::vector<int> nums;
    std::string line;
    char *filename;
    int sort_type;

    // Ensure that at most one type of sort and at least a filename are specified.
    if (argc > 3 || argc < 2)
    {
        usage();
    }

    // default sort is bubble sort
    sort_type = BUBBLE_SORT;

    // Figure out which sort to use
    for (int i = 1; i < argc; ++i)
    {
        char *arg = argv[i];
        if (strcmp(arg, "-b") == 0) { sort_type = BUBBLE_SORT; }
        else if (strcmp(arg, "-q") == 0) { sort_type = QUICK_SORT; }
        else if (strcmp(arg, "-m") == 0) { sort_type = MERGE_SORT; }
        else if (strcmp(arg, "-qi") == 0) { sort_type = QUICK_SORT_INPLACE; }
        else { filename = argv[i]; }
    }

    // Read the file and fill our vector of integers
    // THIS FUNCTION IS STUDENT IMPLEMENTED
    readFile(filename, nums);

    switch (sort_type)
    {
        case BUBBLE_SORT:
        print_vector(bubbleSort(nums));
        break;

        case QUICK_SORT:
        print_vector(quickSort(nums));
        break;

        case MERGE_SORT:
        print_vector(mergeSort(nums));
        break;

        case QUICK_SORT_INPLACE:
        quicksort_inplace(nums, 0, nums.size() - 1);
        print_vector(nums);
        break;

        default:
        usage();
        break;
    }
    return 0;
}

/**
 * Usage    Prints out a usage statement and exits.
 */
void usage()
{
    fprintf(stderr, "%s", usage_string);
    exit(1);
}

/**
 * TO STUDENTS: In all of the following functions, feel free to change the
 * function arguments and/or write helper functions as you see fit. Remember to
 * add the function header to sorter.h if you write a helper function!
 */

 /**
 * On the first traversal of the loop. We compare adjacent elements, and move the 
 * greater one to the right. At the end of the loop. The greatest element is at the end.
 * On the next loop, we don't have to sort all the way to the end. Because we already
 * know the greatest number is there. So, we can stop one short. We do this until there's
 * only one element left to be sorted. 
 * 
 * targetlength = length of list - 1
 * while target length != 1
 *      for (int i from 0 all the way to target length):
 *           if list[i+1] > list[i]
 *               swap[i+1] [i]
 * target length - 1
 */
std::vector<int> bubbleSort(std::vector<int> &list)
{
    bool swapped = true;
    int j = 0;
    int temp1;
    int temp2;
    while (swapped == true)
    {
        swapped = false;
        j++;
        for (unsigned int i = 0; i < list.size() - j; i++)
        {
            if (list[i] > list[i + 1])
            {
                temp1 = list[i];
                temp2 = list[i + 1];
                list[i] = temp2;
                list[i + 1] = temp1;
                swapped = true;

            }

        }
    }
    return list;
}

/**
 * What we want to do is have three empty arrays in the beginning. (less,equal,greater)
 * We're going to select a random pivot point of the array.
 * Then we traverse the list, and anything less than the pivot we add it to 
 * the less array, anything equal we add to the equal array, and everything greater
 * we add to the greater.
 * We then call quicksort on less and greater. Then we concatenate less, equal and greater.
 *
 *
 */
 std::vector<int> quickSort(std::vector<int> &list)
{
    vector <int> less, equal, greater;
    if (list.size() > 1)
    {
        int pivot = list[rand() % list.size()];
        for (unsigned int i = 0; i < list.size(); i++)
        {
            int x = list[i];
            if (x < pivot)
            {
                less.push_back(x);
            }
            else if (x == pivot)
            {
                equal.push_back(x);
            }
            else
            {
                greater.push_back(x);
            }
        }
        less = quickSort(less);
        greater = quickSort(greater);
        for (unsigned int i = 0; i < equal.size(); i++)
        {
            less.push_back(equal[i]);
        }
        for (unsigned int i = 0; i < greater.size(); i++)
        {
            less.push_back(greater[i]);
        }
        return less;
    }
    return list;
}

/**
 * We already have a merge function. So in this function we want to recursively
 * split the list until it is only one element. Then merge these one element lists.
 * This will get the job in nlogn time.
 * 
 * if size of list < 2:
 *      return list;
 * else:
 *    splitleft = left
 *    splitright = right
 *    mergeSort(left)
 *    mergeSort(right)
 *    return merge(left,right)
 */
std::vector<int> mergeSort(std::vector<int> &list)
{
    unsigned int m = list.size() / 2;
    vector <int> first;
    vector <int> second;
    vector <int> sorted; 
    if (list.size() < 2)
    {
        return list;
    }
    else
    {
        for (unsigned int i = 0; i < m; i++)
        {
            first.push_back(list[i]);
        }
        for (unsigned int j = m; j < list.size(); j++)
        {
            second.push_back(list[j]);
        }
        first = mergeSort(first);
        second = mergeSort(second);
        sorted = merge(first,second);
    }
    return sorted;
}


/**
 * What this function will do is take two sorted lists.
 * Then it will compare it element by element, and then add it in increasing
 * order. 
 * 
 *  while left hasnt been added fully and right hasnt been added fully:
 *           if left is bigger than right add left to the array
 *           if right is bigger than left add right to the array
 *           if one of the arrays is done. add everything to it.
 */
std::vector<int> merge(std::vector<int> &left, std::vector<int> &right)
{
    unsigned int leftCounter = 0;
    unsigned int rightCounter = 0;
    vector <int> merged;
    while ((leftCounter != left.size()) || (rightCounter != right.size()))
    {
        if ((leftCounter != left.size()) && (rightCounter != right.size()))
        {
            if (left[leftCounter] <= right[rightCounter])
            {
                merged.push_back(left[leftCounter]);
                leftCounter++;
            }
            else
            {
                merged.push_back(right[rightCounter]);
                rightCounter++;
            }
        }
        else
        {
            if (leftCounter != left.size())
            {
                while (leftCounter != left.size())
                {
                    merged.push_back(left[leftCounter]);
                    leftCounter++;
                }
            }
            else
            {
                while (rightCounter != right.size())
                {
                    merged.push_back(right[rightCounter]);
                    rightCounter++;
                }

            }
        }
    }
    return merged;
}

/*
 * quicksort_inplace:  In-place version of the quicksort algorithm. Requires
 *              O(1) instead of O(N) space, same time complexity. Each call of
 *              the method partitions the list around the pivot (an item taken
 *              from the middle of the array) with items left of the pivot
 *              smaller than it and items to its right larger than it. Then the
 *              method recursively sorts the left and right portions of the list
 *              until it reaches its base case: a list of length 1 is already
 *              sorted.
 *
 * @param list: pointer to integer array to be sorted
 * @returns:    Nothing, the array is sorted IN-PLACE.
 *
 * TODO: Implement this function.
 */
void quicksort_inplace(std::vector<int> &list, int left, int right)
{
    int i = left, j = right;
    int temp1, temp2;
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
                i++;
                j--;
            }
    }
    
    if (left < j)
    {
        quicksort_inplace(list, left, j);
    }
    if (i < right)
    {
        quicksort_inplace(list, i, right);
    }
}