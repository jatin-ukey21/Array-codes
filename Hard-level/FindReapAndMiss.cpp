#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    //APPROACH 1
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        map<int,int> mpp;
        for(int i = 0;i < arr.size(); i++){
            mpp[arr[i]]++;
        }
        int missing = -1, repeating = -1;
        for(int i = 1;i <= arr.size(); i++){
            if(mpp[i] == 0) missing = i;
            else if(mpp[i] == 2) repeating = i;
            
            if(missing != -1 && repeating != -1){
                break;
            }
        }
        
        return {repeating,missing};
    }

    //APPROACH 2
    vector<int> findTwoElement(vector<int>& arr) {
        // We are given an array from 1 to n where:
        // One number is missing (let's say y)
        // One number is repeating (let's say x)
        // We need to return {x, y}

        long long n = arr.size();

        // Calculate the expected sum of first n natural numbers: SN = n(n+1)/2
        long long SN = (n * (n + 1)) / 2;

        // Calculate the expected sum of squares of first n natural numbers: S2N = n(n+1)(2n+1)/6
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

        long long S = 0, S2 = 0;

        // Calculate the actual sum (S) and sum of squares (S2) from the input array
        for(int i = 0; i < n; i++){
            S += arr[i];  // Sum of array elements
            S2 += (long long)arr[i] * (long long)arr[i];  // Sum of squares of array elements
        }

        // Let:
        // x = repeating number
        // y = missing number

        // Equation 1: S - SN = x - y
        long long val1 = S - SN;  // x - y

        // Equation 2: S2 - S2N = x^2 - y^2 = (x - y)(x + y)
        long long val2 = S2 - S2N;

        // From (x^2 - y^2)/(x - y) = x + y
        val2 = val2 / val1;  // x + y

        // Solve equations:
        // x - y = val1
        // x + y = val2
        // Adding both equations: 2x = val1 + val2 => x = (val1 + val2)/2
        long long x = (val1 + val2) / 2;

        // From x - y = val1 => y = x - val1
        long long y = x - val1;

        // Return in the format {repeating, missing}
        return {(int)x, (int)y};
    }
};