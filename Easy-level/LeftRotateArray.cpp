#include<bits/stdc++.h>
using namespace std;

//Note: consider the array as circular
class Solution {
  public:

    // BRUTE FORCE
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d%n;  // Handle cases where d is greater than the size of the array
        // store the first d elements
        vector<int> temp(d);
        for(int i = 0; i < d; i++) temp[i] = arr[i];
        
        //now rorate the elements after d
        for(int i = d; i < n;i++){
            arr[i - d] = arr[i];
        }
        
        //store the first d elements after d+1 elements
        for(int i = n - d;i < n;i++){
            arr[i] = temp[i - (n - d)];
        }
    }

    // OPTIMAL
    void rotateArr2(vector<int>& arr, int d) {
        
        d = d % arr.size();  // Handle cases where d is greater than the size of the array
        //first reverse d elements
        reverse(arr.begin(),arr.begin()+d);
        
        //then reverse n-d elements
        reverse(arr.begin()+d,arr.end());
        
        //now rotate whole array
        reverse(arr.begin(),arr.end());
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int d = 2;

    sol.rotateArr(arr, d);
    cout << "Array after left rotation (Brute Force): ";
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7};
    sol.rotateArr2(arr2, d);
    cout << "Array after left rotation (Optimal): ";
    for(int num : arr2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}