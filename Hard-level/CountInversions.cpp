/*
Problem statement:-
There is an integer array ‘A’ of size ‘N’.

Number of inversions in an array can be defined as the number of pairs of ‘i’, ‘j’ such that ‘i’ < ‘j’ and ‘A[i]’ > ‘A[j]’.
You must return the number of inversions in the array.

For example,
Input:
A = [5, 3, 2, 1, 4], N = 5
Output:
7
Explanation: 
The pairs satisfying the condition for inversion are (1, 2), (1, 3), (1, 4), (1, 5), (2, 3), (2, 4), and (3, 4). 
The number of inversions in the array is 7.
*/
#include <bits/stdc++.h>
using namespace std;

// Merge function that merges two sorted halves of array `a`
// and counts the number of inversions between them.
int merge(int low, int mid, int high, vector<int>& a) {
    int left = low;        // Starting index of the left subarray
    int right = mid + 1;   // Starting index of the right subarray
    vector<int> temp;      // Temporary array to store merged result

    int cnt = 0; // Count of inversions

    // Merge the two halves while counting inversions
    while (left <= mid && right <= high) {
        if (a[left] > a[right]) {
            // All remaining elements from a[left] to a[mid] will form inversions
            cnt += (mid - left + 1); // Important inversion logic
            temp.push_back(a[right++]);
        } else {
            temp.push_back(a[left++]);
        }
    }

    // Append remaining elements of left half (if any)
    while (left <= mid) temp.push_back(a[left++]);

    // Append remaining elements of right half (if any)
    while (right <= high) temp.push_back(a[right++]);

    // Copy the sorted values back to the original array
    for (int i = low; i <= high; i++) {
        a[i] = temp[i - low];
    }

    return cnt; // Return total inversions in this merge
}

// Recursive Merge Sort function that splits array and counts inversions
int mergeSort(int low, int high, vector<int>& a) {
    int cnt = 0;

    // Base condition: one element has no inversions
    if (low >= high) return cnt;

    int mid = (low + high) / 2;

    // Count inversions in left half
    cnt += mergeSort(low, mid, a);

    // Count inversions in right half
    cnt += mergeSort(mid + 1, high, a);

    // Count cross inversions while merging two sorted halves
    cnt += merge(low, mid, high, a);

    return cnt;
}

// Main function that initiates merge sort and returns inversion count
int numberOfInversions(vector<int>& a, int n) {
    return mergeSort(0, n - 1, a);
}
