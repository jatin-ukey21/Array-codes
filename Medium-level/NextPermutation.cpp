#include <bits/stdc++.h>
using namespace std;

// Function to find the next lexicographical permutation of the given array
/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
The next permutation of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container. If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

For example, the next permutation of arr = [1,2,3] is [1,3,2].
Similarly, the next permutation of arr = [2,3,1] is [3,1,2].
While the next permutation of arr = [3,2,1] is [1,2,3] because [3,2,1] does not have a lexicographical larger rearrangement.
Given an array of integers nums, find the next permutation of nums.

The replacement must be in place and use only constant extra memory.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //1.Start from the second last, find the index where A[i] < A[i+1] and then break
        int n = nums.size();
        int ind = -1;
        for(int i = n - 2; i >= 0; i--){
            if(nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }
        //If no such index found, it is the last permutation in dictionary
        //so reverse it to get the first permutation
        if(ind == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        //2. after finding the A[index], find the number which is slightly 
        //greater than A[index] starting from the last,if found, swap them
        //and break
        for(int i = n - 1; i >= ind; i--){
            if(nums[i] > nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }

        //3.Now sort the elements from index+1 till n-1 elements such that
        //we get slightly bigger permutation than the current one
        sort(nums.begin() + ind + 1,nums.end());
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    sol.nextPermutation(nums);

    // Output the next permutation
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}