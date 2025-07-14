#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //BRUTE FORCE
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        vector<int> temp1, temp2;

        //last k elements
        for(int i = n - k; i < n; i++) temp1.push_back(nums[i]);

        //first n - k elements
        for(int i = 0; i < n - k; i++) temp2.push_back(nums[i]);

        for(int i = 0; i < k; i++) nums[i] = temp1[i];

        for(int i = k; i < n; i++) nums[i] = temp2[i - k];
    }

    //OPTIMAL
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        
        //STEP 1: reverse n - k elements
        reverse(nums.begin(),nums.begin() + n - k);
       
        //Step 2: reverse last k elements
        reverse(nums.begin() + n - k,nums.end());

        //step 3: reverse whole array
        reverse(nums.begin(),nums.end());
    }
};