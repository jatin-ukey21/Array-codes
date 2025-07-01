#include<bits/stdc++.h>
using namespace std;

/*
You are given an array 'a' of size 'n' and an integer 'k'.
Find the length of the longest subarray of 'a' whose sum is equal to 'k'.
(Note: The array 'a' contains only positive integers.)
*/

#include<bits/stdc++.h>
int longestSubarrayWithSumK(vector<int> a, long long k) {
    // Write your code here
    int left = 0;
    int right = 0;
    int n = a.size();

    long long sum = a[0];
    int maxLen = 0;

    while(right < n){
        while(left <= right && sum > k) {
            sum -= a[left];
            left++;
        }
        
        if(sum == k){
            maxLen = max(maxLen,right - left + 1);
        }
        right++;
        if(right < n){
            sum += a[right];
        }
    }
    return maxLen;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    long long k = 9;
    cout << longestSubarrayWithSumK(a, k) << endl; // Output: 3 (subarray [2, 3, 4])
    return 0;
}
