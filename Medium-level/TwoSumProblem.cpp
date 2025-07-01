#include<bits/stdc++.h>
using namespace std;

/*
Given an array of integers, your task is to find two numbers such that they add up to a specific target number.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //refer problem of longest subarray with target k
        map<int,int> mpp; //{sum,index}

        
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            int moreNeeded = target - num;

            if(mpp.find(moreNeeded) != mpp.end()){
                return {mpp[moreNeeded], i};
            }
            // Store the current number and its index in the map
            mpp[num] = i;
        }

        return {-1,-1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = sol.twoSum(nums, target);
    
    if (result[0] != -1) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl; // Output: Indices: 0, 1
    } else {
        cout << "No two sum solution found." << endl;
    }
    
    return 0;
}