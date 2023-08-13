#include <iostream>

// Function to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate GCD of an array of integers
int arrayGCD(int arr[], int size) {
    int result = arr[0];
    for (int i = 1; i < size; i++) {
        result = gcd(result, arr[i]);
        if (result == 1)  // If GCD becomes 1, further calculations are unnecessary
            return 1;
    }
    return result;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10};  // Example array
    int size = sizeof(arr) / sizeof(arr[0]);

    int gcdResult = arrayGCD(arr, size);
    std::cout << "GCD of the array: " << gcdResult << std::endl;

    return 0;
}
