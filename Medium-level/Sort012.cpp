#include<bits/stdc++.h>
using namespace std;

/*
Given an array nums with n objects colored red, white, or blue,
 sort them in-place so that objects of the same color are adjacent, 
 with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function
*/

class Solution {
public:
    // BETTER APPROACH
    // This method counts the occurrences of each color (0, 1, 2) and then fills the array
    // with the counted values in the correct order.
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int cnt0 = 0;
        int cnt1 = 0;
        int cnt2 = 0;

        for(int i = 0; i < n;i++){
            if(nums[i] == 0) cnt0++;
            else if(nums[i] == 1) cnt1++;
            else cnt2++;
        }

        int ind = 0;
        for(int i=0;i<cnt0;i++) nums[ind++] = 0;
        for(int i=0;i<cnt1;i++) nums[ind++] = 1;
        for(int i=0;i<cnt2;i++) nums[ind++] = 2;
    }

    // OPTIMAL APPROACH
    // This method uses the Dutch National Flag problem algorithm to sort the colors in a single pass.
    // DNF = Dutch National Flag Algorithm
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0, mid = 0, high = n - 1;

        /*
        The idea is to partition the array into 4 segments:

        | 0..low-1 |  low..mid-1  |  mid..high  | high+1..n-1 |
          all 0's     all 1's        unknown       all 2's
                                  (unsorted 0/1/2)
        - elements from 0 to low-1 are guaranteed to be 0
        - elements from low to mid-1 are guaranteed to be 1
        - elements from mid to high are unknown(unsorted), to be processed
        - elements from high+1 to n-1 are guaranteed to be 2

        We process mid, and shift numbers to their correct segments
        */

        while (mid <= high) {
            if (nums[mid] == 0) {
                /*
                  Encounter 0:
                  - swap it to low position
                  - grow the region of 0's
                  - mid moves forward since swapped element is definitely handled
                */
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if (nums[mid] == 1) {
                /*
                  Encounter 1:
                  - already in correct place
                  - expand the middle region (1's)
                */
                mid++;
            }
            else if (nums[mid] == 2) {
                /*
                  Encounter 2:
                  - push it to high side
                  - shrink high boundary
                  - do *not* increment mid since swapped element
                    might be 0/1 and needs processing
                */
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);
    
    for (int num : nums) {
        cout << num << " "; // Output: 0 0 1 1 2 2
    }
    cout << endl;

    return 0;
}