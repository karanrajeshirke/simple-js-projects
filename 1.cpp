#include<iostream>
#include<climits> // For INT_MAX and INT_MIN
using namespace std;

void findMinMax(int arr[], int low, int high, int &minVal, int &maxVal) {
    // Base Case: If the array contains only one element
    if (low == high) {
        minVal = maxVal = arr[low];
        return;
    }

    // Base Case: If the array contains two elements
    if (high == low + 1) {
        if (arr[low] < arr[high]) {
            minVal = arr[low];
            maxVal = arr[high];
        } else {
            minVal = arr[high];
            maxVal = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int leftMin, leftMax, rightMin, rightMax;

    // Recursively find min and max in left and right halves
    findMinMax(arr, low, mid, leftMin, leftMax);
    findMinMax(arr, mid + 1, high, rightMin, rightMax);

    // Merge the results
    minVal = min(leftMin, rightMin);
    maxVal = max(leftMax, rightMax);
}

int main() {
    int arr[] = {11, 9, 10, 25, 8, 15, 4, 13, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    int minVal, maxVal;
    findMinMax(arr, 0, n - 1, minVal, maxVal);

    cout << "Minimum element in the array: " << minVal << endl;
    cout << "Maximum element in the array: " << maxVal << endl;

    return 0;
}
