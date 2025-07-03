#include<bits/stdc++.h>
using namespace std;

// Rearrange the array elements by size
// Given an array of integers, rearrange the elements such that all even numbers come before all
// odd numbers, while maintaining the relative order of even and odd numbers.
class Solution {
public:
    // BRUTE FORCE
    vector<int> rearrangeArray(vector<int>& nums) {
        //posituve elements index are even and negative elements index are odd
        vector<int> pos, neg;

        // Separate even and odd numbers
        for(int num : nums) {
            if(num % 2 == 0) {
                pos.push_back(num);
            } else {
                neg.push_back(num);
            }
        }

        // Concatenate even and odd vectors
        pos.insert(pos.end(), neg.begin(), neg.end());
        return pos;
    }

    // OPTIMIZED
    vector<int> rearrangeArray2(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int posIndx = 0, negIndx = 1;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                ans[negIndx] = nums[i];
                negIndx += 2;
            }
            else{
                ans[posIndx] = nums[i];
                posIndx += 2;
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Using the brute force method
    vector<int> result1 = sol.rearrangeArray(nums);
    cout << "Rearranged Array (Brute Force): ";
    for(int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    // Using the optimized method
    vector<int> result2 = sol.rearrangeArray2(nums);
    cout << "Rearranged Array (Optimized): ";
    for(int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}