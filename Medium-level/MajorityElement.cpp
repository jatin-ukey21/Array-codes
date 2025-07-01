#include<bits/stdc++.h>
using namespace std;

/*
,Given an array of size n, find the majority element in the array.
The majority element is the element that appears more than n/2 times in the array.

The Boyer-Moore Voting Algorithm is an efficient algorithm to find the majority element in an array.

***INTUITION***
Why “voting”?  --->
Think of it like an election:

every element is a “candidate”

you vote for a candidate

if someone is majority, they will eventually win in a fair election even after canceling out other votes.

Core Intuition:--->
You start with no candidate (count = 0)

As you scan through the array, you vote:

if your current count is 0, you choose a new candidate

if the current number equals your candidate, you increment its count

if it does not, you decrement the count (meaning you “cancel” a vote)

Why does this work?  --->

Majority element appears more than n/2 times

So even if you cancel out votes with other elements, the majority will still survive:

the majority's count advantage exceeds all others combined

it cannot be completely canceled out because it occurs more than half

At the end, the candidate you hold is guaranteed to be the majority if one exists. (You may need a second pass to verify.)
*/

class Solution {
public:
    // Moore's Voting Algorithm
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;     // this represents the current "vote count"
        int elem;        // this represents the current "candidate"

        for(int i = 0; i < n; i++){
            if(cnt == 0){
                // no votes left, choose a new candidate
                elem = nums[i];
                cnt = 1;
            }
            else if(nums[i] == elem){
                // same as current candidate, add one vote
                cnt++;
            }
            else{
                // different from current candidate, cancel one vote
                cnt--;
            }
        }

        /*
         Explanation of why this works:
         - Majority element appears more than n/2 times
         - even after repeatedly canceling out votes from other numbers,
           it cannot be completely eliminated
         - it will be the last remaining candidate at the end
        */

        // **optional validation step**
        // If there is no guarantee a majority element exists in the array,
        // you must do a second pass to confirm elem's count > n/2
        return elem;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {3, 2, 3};
    cout << sol.majorityElement(nums) << endl; // Output: 3
    return 0;
}