/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world. */

#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int* arr, int len) {
    for (int i = 1; i < len; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int* FindAltSort(int* arr, int len) {
    bubbleSort(arr, len);  // Sorting the array in ascending order
    
    for(int i = 0 ; i < len ; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    int* result = new int[(len / 2) + 1];  // Creating a new array to store the alternate elements
    for (int i = 0, j = 0; i <= len; i += 2, j++) {
        result[j] = arr[i];  // Storing alternate elements in the new array
    }

    return result;
}

int main() {
    int arr[] = {16, 15, 11, 8, 9, 5, 3, 2, 1};
    // int arr[] = {3,5,1,5,9,10,2,6};
    int len = sizeof(arr) / sizeof(arr[0]);

    int* altSorted = FindAltSort(arr, len);

    std::cout << "Alternate Sorted Array: ";
    for (int i = 0; i < len / 2; i++) {
        std::cout << altSorted[i] << " ";
    }
    std::cout << std::endl;

    delete[] altSorted;  // Deallocating the dynamically allocated memory

    return 0;
}
