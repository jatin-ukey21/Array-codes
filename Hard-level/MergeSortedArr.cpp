#include <bits/stdc++.h>
using namespace std;

//BETTER APPROACH - 1
class Solution {
public:
    /*
     Time Complexity
    Swap loop: O(min(n, m))
    Sort nums1[0...n-1]: O(n log n)
    Sort nums2: O(m log m)
    Copy nums2 into nums1: O(m)
    ➡️ Overall: O(n log n + m log m)
    */
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int left = n - 1; // Pointer at the last valid element in nums1
        int right = 0;    // Pointer at the first element in nums2

        // Step 1: Swap larger elements from the end of nums1 with smaller
        // elements from the start of nums2 This helps in roughly positioning
        // elements such that smaller elements are in nums1 and larger ones move
        // to nums2
        while (left >= 0 && right < m) {
            if (nums1[left] > nums2[right]) {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            } else {
                // If the current element in nums1 is already smaller or equal,
                // no more swaps are needed
                break;
            }
        }

        // Step 2: Sort the first 'n' elements of nums1 which now contain the
        // smallest elements
        sort(nums1.begin(), nums1.begin() + n);

        // Step 3: Sort the entire nums2 array as its values may have changed
        // due to swapping
        sort(nums2.begin(), nums2.end());

        // Step 4: Copy all elements of nums2 into the remaining positions of
        // nums1
        for (int i = 0; i < m; i++) {
            nums1[n + i] = nums2[i];
        }
    }
};
//BETTER APPROACH - 2
class Solution {
public:
    // Utility to compare and swap if needed
    void swapIfGreater(int ind1, int ind2, vector<int>& arr1, vector<int>& arr2){
        if(arr1[ind1] > arr2[ind2]){
            swap(arr1[ind1], arr2[ind2]);
        }
    }
    //Time Complexity:
    // O((n + m) log(n + m))
    //SHELL SORT GAP METHOD TECHNIQUE IS USED HERE
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int gap = (n + m) / 2 + (n + m) % 2; // Initial gap = ceil((n + m) / 2)

        while(gap > 0){
            int left = 0;
            int right = left + gap;

            while(right < (n + m)){
                // Case 1: both pointers in nums1
                if(left < n && right < n){
                    if(nums1[left] > nums1[right]){
                        swap(nums1[left], nums1[right]);
                    }
                }
                // Case 2: left in nums1, right in nums2
                else if(left < n && right >= n){
                    if(nums1[left] > nums2[right - n]){
                        swap(nums1[left], nums2[right - n]);
                    }
                }
                // Case 3: both pointers in nums2
                else {
                    if(nums2[left - n] > nums2[right - n]){
                        swap(nums2[left - n], nums2[right - n]);
                    }
                }

                left++;
                right++;
            }

            // Reduce gap
            if(gap == 1) break;
            gap = (gap / 2) + (gap % 2);  // Equivalent to ceil(gap / 2)
        }

        // Copy sorted nums2 into nums1 starting at index n
        for(int i = 0; i < m; i++){
            nums1[n + i] = nums2[i];
        }
    }
};
