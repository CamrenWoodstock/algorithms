#include <iostream>

/* 
Camren Woodstock

BREAKDOWN STEP BY STEP RADIX SORT (Psuedocode)

Radix sort is a sorting algorithm that is used to sort numnbers
The numbers will be sorted from least significant digit to the most significant digit.
If we have an array of 10 unsorted numbers, we need 10 buckets labeled 0 to 9
to sort the unsorted numbers.

1. First step is to find the number of digits in the biggest number. Say 3 digits
is the largest number, so will have to do 3 passes.

2. Second step is to pad all the numbers that are smaller than the biggest
with leading zeros in order to make them all have the same amount of digits

**Note: The sorting process depends on how many digits there are in the biggest
number, so if the biggest number has 3 digits, the process will take 3 passes.

3. The third step is the first pass, sort the numbers using the first digit from the
right. Put the element of the array in a bucket 0-9 according to its first digit. The
buckets may have more than 1 number in them on the first pass.

4. The forth step is to take the numbers out from each bucket 0-9 from bottom. Then
perform a second pass sorting the numbers using the second digit on the right and
put them in their corresponding container.

5. The fifth step is to take the numbers out from the bucket 0-9 from bottom like we
did before. Then perform a third pass sorting the numbers using the third digit on the
right and put them in their corresponding container. 

6. The sixth step is take the number out from each bucket 0-9 from bottom and all the
numbers should be in order. 

7. The seventh step is to remove the leading zeros from the numbers smaller than the
max.

8. You're all done the numbers should be sorted in ascending order.

 */

// This function finds the most significant digit in the array.
// O(n)
int msd(int arr[], int len)
{
    int max = arr[0];
    for (int i = 1; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// Countsort on the arr[]
/*
count [i] array will be counting the number of array
 values have that 'i' digit at their (exp)th place

count the number of times each digit occured at the
(exp)th place in every input
 */
void csort(int arr[], int len, int exp)
{
    int output[len];
    int i;
    // numbers 0-9, because we are only looking at one digit at a time.
    int count[10] = {0};

    /* This for loop counts the number of times each digit,
    occurs at the (exp)th place in every input and stores
    the number of times in the count array.
    */
    for (i = 0; i < len; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }
    /* Calculate their cumulative count
    by setting i = 1, and set count[i] = count[i] + count[i - 1];
    *Note count[0] is already set from the previous for loop where (arr[i]/exp)%10
    */
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    // Building the output array, reading the numbers from last to first
    for (i = len - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    //Copying the new output to the original array
    for (i = 0; i < len; i++)
    {
        arr[i] = output[i];
    }
}
//sort arr[] size len, using Radix sort
void radix_sort(int arr[], int len)
{
    // Find the max number
    int maxD = msd(arr, len);
    // Calling countsort() for digit at (exp)th place
    // in every input
    for (int exp = 1; maxD / exp > 0; exp *= 10)
    {
        csort(arr, len, exp);
    }
}

int main()
{
    int len = 10;
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = rand() % len;
    }
    clock_t start;
    double seconds;
    start = clock();
    radix_sort(arr, len);
    start = clock() - start;
    std::cout << (float)start / CLOCKS_PER_SEC << std::endl;
    return 0;
}