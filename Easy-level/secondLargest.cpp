#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // BRUTE FORCE APPROACH
    int getSecondLargest(vector<int> &arr) {
        // Better approach
        int largest = -1;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] > largest) largest = arr[i];
        }
        
        int slargest = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] > slargest && arr[i] != largest) slargest = arr[i];
        }
        
        return slargest;
    }
    // OPTIMAL APPROACH
    int getSecondLargest2(vector<int> &arr) {
        // Optimal approach
        int largest = -1, slargest = -1;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] > largest) {
                int temp = largest;
                largest = arr[i];
                slargest = temp;
            }
            else if(arr[i] > slargest && arr[i] != largest){
                slargest = arr[i];
            }
        }
        
        
        return slargest;
    }

};

int main() {
    Solution sol;
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    
    int secondLargest = sol.getSecondLargest(arr);
    cout << "Second Largest (Brute Force): " << secondLargest << endl;

    int secondLargest2 = sol.getSecondLargest2(arr);
    cout << "Second Largest (Optimal): " << secondLargest2 << endl;

    return 0;
}