#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //BRUTE FORCE APPROACH
    // This method finds the union of two sorted arrays by merging them into a set to remove
    // duplicates and then converting the set back to a vector.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
       set<int> st;
       
       for(int i = 0; i < a.size(); i++) st.insert(a[i]);
       for(int i = 0; i < b.size(); i++) st.insert(b[i]);
       
       vector<int> unionArr(st.size());
       int i = 0;
       for(auto it: st){
           unionArr[i++] = it;
       }
       
       return unionArr;
    }

    //OPTIMAL APPROACH
    // This method finds the union of two sorted arrays using a two-pointer technique.
     vector<int> findUnion2(vector<int> &a, vector<int> &b) {
       int n = a.size(), m = b.size();
       
       vector<int> unionArr;
       int i = 0,j = 0;
       while(i < n && j < m){
           if(a[i] <= b[j]){
               if(unionArr.size() == 0 || a[i] != unionArr.back()){
                   unionArr.push_back(a[i]);
               }
               i++;
           }
           else{
               if(unionArr.size() == 0 || b[j] != unionArr.back()){
                   unionArr.push_back(b[j]);
               }
               j++;
           }
       }
        
       while(i < n){
           if(unionArr.size() == 0 || a[i] != unionArr.back()){
                   unionArr.push_back(a[i]);
               }
               i++;
       }
       
       while(j < m){
           if(unionArr.size() == 0 || b[j] != unionArr.back()){
                   unionArr.push_back(b[j]);
               }
               j++;
       }
       
       return unionArr;
    }
};

int main() {
    Solution sol;
    vector<int> a = {1, 2, 4, 5};
    vector<int> b = {2, 3, 5, 6};

    vector<int> unionArr = sol.findUnion(a, b);
    cout << "Union of two sorted arrays (Brute Force): ";
    for(int num : unionArr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> unionArr2 = sol.findUnion2(a, b);
    cout << "Union of two sorted arrays (Optimal): ";
    for(int num : unionArr2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}