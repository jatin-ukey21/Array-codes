//Count inversions in an array problem reference used here
/*
Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where:

0 <= i < j < nums.length and
nums[i] > 2 * nums[j].
*/
class Solution {
public:
    /*
     Time Complexity
      Each level of merge sort has a cost of O(n) for:
      Counting pairs (countPairs) (n1 + n2 = n)
      Merging (merge)
      There are log(n) levels in recursion (like standard merge sort)
      Overall Time Complexity: O(2n*log n)
    */
    // Standard merge function used in merge sort to merge two sorted halves
    void merge(int low, int mid, int high, vector<int>& a) {
        int left = low;      // Pointer for the left subarray
        int right = mid + 1; // Pointer for the right subarray
        vector<int> temp;

        // Merge the two sorted halves into a temporary array
        while (left <= mid && right <= high) {
            if (a[left] > a[right]) {
                temp.push_back(a[right++]);
            } else {
                temp.push_back(a[left++]);
            }
        }

        // Append remaining elements from left subarray
        while (left <= mid)
            temp.push_back(a[left++]);

        // Append remaining elements from right subarray
        while (right <= high)
            temp.push_back(a[right++]);

        // Copy the merged and sorted values back to the original array
        for (int i = low; i <= high; i++) {
            a[i] = temp[i - low];
        }
    }

    // This function counts the number of important reverse pairs
    // i.e., pairs (i, j) such that i < j and a[i] > 2 * a[j]
    int countPairs(int low, int mid, int high, vector<int>& a) {
        int cnt = 0;
        int right = mid + 1;

        // For each element in left half, find how many elements in right half
        // satisfy the condition a[i] > 2 * a[j]
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)a[i] > 2LL * a[right]) {
                right++;
            }
            cnt += (right - (mid + 1)); // Number of valid j’s for this i
        }

        return cnt;
    }

    // Modified merge sort function that counts reverse pairs
    int mergeSort(int low, int high, vector<int>& a) {
        int cnt = 0;

        // Base case: single element has no pairs
        if (low >= high)
            return cnt;

        int mid = (low + high) / 2;

        // Count pairs in left and right halves
        cnt += mergeSort(low, mid, a);
        cnt += mergeSort(mid + 1, high, a);

        // Count reverse pairs across halves
        cnt += countPairs(low, mid, high, a);

        // Merge the two sorted halves
        merge(low, mid, high, a);

        return cnt;
    }

    // Main function to call
    int reversePairs(vector<int>& nums) {
        return mergeSort(0, nums.size() - 1, nums);
    }
};
