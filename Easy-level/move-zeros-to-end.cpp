#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE APPROACH
class Solution {
public:
    //BRUTE FORCE
    void moveZeroes(vector<int>& nums) {
        //first collect non zero elements
        vector<int> temp;
        for(int i = 0;i < nums.size();i++) if(nums[i] != 0) temp.push_back(nums[i]);

        //now place the non-zero elements at front
        for(int i = 0; i < temp.size();i++) nums[i] = temp[i];

        //now push the n-k zero to the end of array, k is size of temp[]
        for(int i = temp.size();i < nums.size(); i++) nums[i] = 0;
    }

    //OPTIMAL
    void moveZeroes2(vector<int>& nums) {
        //find the first zero element index
        // Initialize j to -1, which will store the index of the first zero found
        int j = -1;
        for(int i=0;i < nums.size();i++){
            if(nums[i] == 0){
                j = i;
                break;
            }
        }
        if(j == -1) return;

        for(int i = j + 1; i < nums.size(); i++){
            //if the current element is a non zero element, then swap so that
            //eventually non-zeros will come to front and zeros will come to the end
            if(nums[i] != 0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {0, 0, 1};
    sol.moveZeroes2(nums2);
    for(int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}