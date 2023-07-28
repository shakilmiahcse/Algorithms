#include <iostream>
#include <vector>
using namespace std;

// Function to swap two elements in the array
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Quick Sort algorithm
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];  // Choose the last element as the pivot
        int i = low - 1;        // Index of the smaller element

        for (int j = low; j < high; j++) {
            // If the current element is smaller than or equal to the pivot
            // for descending order: arr[j] >= pivot
            if (arr[j] <= pivot) {
                i++; // Increment the index of the smaller element
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]); // Swap the pivot to its correct position

        // Recursive calls for the two sub-arrays
        quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

// Helper function to print the elements of the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    printArray(arr);

    int n = arr.size();
    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}

