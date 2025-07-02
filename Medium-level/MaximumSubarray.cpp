#include<bits/stdc++.h>
using namespace std;

//Given an integer array nums, find the subarray with the largest sum, and return its sum.
/*
✅ In short: Kadane’s principle

keep a running sum
if running sum goes negative, reset it (no point carrying forward a negative prefix)
track the max sum found along the way
*/
class Solution {
public:
    // Kadane's Algorithm
    int maxSubArray(vector<int>& nums) {
        int sum = 0;                 // running sum of the current subarray
        int maxSum = INT_MIN;        // stores the maximum sum seen so far

        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];          // include current element in running sum

            if(sum > maxSum){
                maxSum = sum;        // update global max if current sum is higher
            }

            if(sum < 0){
                /*
                  if the current sum goes negative,
                  it cannot contribute to any future subarray
                  (because adding a negative to a future positive would only hurt it)
                  → so reset sum to 0 and start a new subarray
                */
                sum = 0;
            }
        }

        return maxSum;  // maximum subarray sum found
    }

    //printing the maximum subarray
    void printMaxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = INT_MIN;
        int start = 0, end = 0, tempStart = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(sum > maxSum) {
                maxSum = sum;
                start = tempStart;
                end = i;
            }

            if(sum < 0) {
                sum = 0;
                tempStart = i + 1; // reset start to the next index
            }
        }

        cout << "Maximum Subarray Sum: " << maxSum << endl;
        cout << "Subarray: ";
        for(int i = start; i <= end; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};
