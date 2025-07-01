#include<bits/stdc++.h>
using namespace std;

/*
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray
 where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

The approach uses a hash map to store the cumulative sum and its corresponding index.
Note that the array can contain both positive and negative integers.
*/

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<long long,int> mpp;
        long long prefixSum = 0;
        int maxLen = 0;
        
        for(int i = 0; i < arr.size(); i++){
            prefixSum += arr[i];
            if(prefixSum == k){
                maxLen = max(maxLen,i + 1);
            }
            long long rem = prefixSum - k; //reverse engg
            if(mpp.find(rem) != mpp.end()){
                int len = i - mpp[rem];
                maxLen = max(len,maxLen);
            }
            
            //due to negatives and zero
            if(mpp.find(prefixSum) == mpp.end()){
                mpp[prefixSum] = i; //got sum till ith index
            }
        }
        
        return maxLen;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, -1, 5, -2, 3};
    int k = 3;
    cout << sol.longestSubarray(arr, k) << endl; // Output: 4 (subarray [1, -1, 5, -2])
    return 0;
}