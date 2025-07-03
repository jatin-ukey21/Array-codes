#include<bits/stdc++.h>
using namespace std;

// Rearrange the array elements by size
// Given an array of integers, rearrange the elements such that all positive numbers come before all
// negative numbers, while maintaining the relative order of positive and negative numbers.
// This is a variation of the problem where we rearrange elements by sign.

/*
Note:
- Resulting array should start with a positive integer (0 will also be considered as a positive integer).
- If any of the positive or negative integers are exhausted, then add the remaining integers in the answer as it is by maintaining the relative order.
- The array may or may not have the equal number of positive and negative integers.
*/

// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // TC :- O(N) + O(N) = O(2N)
        vector<int> pos, neg;
        int n = arr.size();
        
        for(int i = 0; i < n; i++){
            if(arr[i] < 0) neg.push_back(arr[i]);
            else pos.push_back(arr[i]);
        }
        
        if(pos.size() > neg.size()){
            for(int i = 0; i < neg.size(); i++){
                arr[2 * i] = pos[i];
                arr[2 * i + 1] = neg[i];
            }
            
            //still positives left over
            int index = 2 * neg.size(); 
            for(int i = neg.size(); i < pos.size(); i++){
                arr[index++] = pos[i];
            }
        }
        else{
            for(int i = 0; i < pos.size(); i++){
                arr[2 * i] = pos[i];
                arr[2 * i + 1] = neg[i];
            }
            
            //still positives left over
            int index = 2 * pos.size(); 
            for(int i = pos.size(); i < neg.size(); i++){
                arr[index++] = neg[i];
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, -2, 3, -4, 5, -6, 7, -8, 9};
    
    sol.rearrange(arr);
    
    cout << "Rearranged Array: ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}