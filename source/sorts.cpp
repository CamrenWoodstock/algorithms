#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sorts.hpp"

/* Helper Functions */

void copy_arr(int* arr, int* temp, int n) {
  for (int i = 0; i < n; i++) {
    temp[i] = arr[i];
  }
}

void swap(int* y, int* x) {
  int temp;
  temp = *y;
  *y = *x;
  *x = temp;
}

/** Bubble Sort
 *  O(n^2), Omega(n)
 */
void bubble_sort(int* arr, int n) {
  for (int i = 0; i < (n - 1); i++) {
    if (arr[i] > arr[i + 1]) {
      arr[i] = arr[i] xor arr[i + 1];
      arr[i + 1] = arr[i] xor arr[i + 1];
      arr[i] = arr[i] xor arr[i + 1];
    }
  }
  if (n != 1) {
    bubble_sort(arr, n - 1);
  }
}

void selection_sort(int* arr, int n) {
  for (int i = 0; i < (n - 1); i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    swap(&arr[min], &arr[i]);
  }
}

void insertion_sort(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      swap(&arr[j], &arr[j - 1]);
    }
  }
}

void merge(int* arr, int n, int mid) {
  int* temp = new int[n];
  copy_arr(arr, temp, n);

  int j = 0;
  int k = mid;
  for (int i = 0; i < n; i++) {
    if (j >= mid) {
      arr[i] = temp[k];
      k++;
    } else if (k >= n) {
      arr[i] = temp[j];
      j++;
    } else if (temp[j] < temp[k]) {
      arr[i] = temp[j];
      j++;
    } else {
      arr[i] = temp[k];
      k++;
    }
  }
  delete[] temp;
}

void mergesort(int* arr, int n) {
  if (n > 1) {
    mergesort(arr, n / 2);
    mergesort(arr + (n / 2), n - n / 2);
    merge(arr, n, n / 2);
  }
}


int partition(int arr[], int low, int high) {

  int pivot = arr[high];
  int i = low - 1; // yes this is equal to -1

// Go through elements j = low all the way to high
  for (int j = low; j < high; j++) {
    if ( arr[j] <= pivot) {
      i++; // index of the smaller element 
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// arr is the array to be sorted
// left is the starting index 
// right is the end index
void quicksort(int arr[], int left, int right) {
  if (left < right) {
    // set a partitioning index;
    int pIndex = partition(arr, left, right);

    // sort elements before and after partition 
    quicksort(arr, left, pIndex - 1);
    quicksort(arr, pIndex + 1, right);
  }

}


void quicksort(int* arr, int n){
  
}