#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // BRUTE FORCE
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // Your code here
        vector<int> visited(arr2.size(),0);
        vector<int> intersectionArr;
        for(int i = 0; i < arr1.size(); i++){
            for(int j = 0; j < arr2.size(); j++){
                if(arr1[i] == arr2[j] && visited[j] == 0){
                    intersectionArr.push_back(arr1[i]);
                    visited[j] = 1;
                }
            }
        }
        
        return intersectionArr;
    }

    // OPTIMAL 
    vector<int> intersection2(vector<int> &arr1, vector<int> &arr2) {
        // Your code here
        vector<int> intersectionArr;
        int i = 0,j = 0;
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] < arr2[j]){
                i++;
            }
            else if(arr2[j] < arr1[i]){
                j++;
            }
            else{
                if(intersectionArr.size() == 0 || intersectionArr.back() != arr1[i]){
                    intersectionArr.push_back(arr1[i]);
                }
                
                i++; j++;
            }
        }
        
        return intersectionArr;
    }
};