#include<bits/stdc++.h>
using namespace std;

/*
You are given an array arr of positive integers. Your task is to find all the leaders in the array. 
An element is considered a leader if it is greater than or equal to all elements to its right. 
The rightmost element is always a leader.
*/


class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        int maxi = INT_MIN;
        int n = arr.size();
        vector<int> ans;
        for(int i = n - 1; i >= 0; i--){
            if(arr[i] >= maxi){
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    
    vector<int> leaders = sol.leaders(arr);
    
    // Output the leaders
    for (int leader : leaders) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}