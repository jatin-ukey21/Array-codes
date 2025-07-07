#include<bits/stdc++.h>
using namespace std;

/*
✅ Why the extra conditions like nums[i] != ele2 and nums[i] != ele1?
These are critical for avoiding duplicate candidates.

Imagine you have cnt1 == 0, and you're about to assign nums[i] to ele1 If ele2 already holds that same number
, and you don’t check nums[i] != ele2, then both ele1 and ele2 will point to the same number, 
defeating the logic of tracking two unique candidates
Same logic applies to cnt2 == 0 && nums[i] != ele1.

This ensures that:

ele1 and ele2 are always distinct candidates Each candidate only holds a unique element to track
*/
class Solution {
public:
    // Extended Moore's Voting Algorithm for Majority Element II
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;               // counters for two potential majority elements
        int ele1 = INT_MIN, ele2 = INT_MIN;   // placeholders for the two candidates
        int n = nums.size();

        /*
          Why at most 2 elements?

          If an element appears more than ⌊n/3⌋ times,
          there can be **at most 2 such elements** in the array.
          Because:
            - If there were 3 elements with > n/3 occurrences,
              that would mean more than n total elements, which is impossible.

          So we are allowed to track only 2 candidates.
        */

        // 1st pass — find potential candidates using extended Moore's Voting
        for(int i = 0; i < n; i++) {
            if(cnt1 == 0 && nums[i] != ele2){
                // assign new candidate to ele1 if cnt1 is empty and nums[i] ≠ ele2
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                // assign new candidate to ele2 if cnt2 is empty and nums[i] ≠ ele1
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(nums[i] == ele1) {
                cnt1++;  // increment vote for ele1
            }
            else if(nums[i] == ele2) {
                cnt2++;  // increment vote for ele2
            }
            else {
                // neither matched, reduce vote count of both
                cnt1--;
                cnt2--;
            }
        }

        /*
          The above pass gives us 2 possible candidates,
          but they are not guaranteed to be correct.
          So we must verify their actual counts in a second pass.
        */
        cnt1 = 0;
        cnt2 = 0;
        int mini = (int)(n / 3) + 1;  // threshold to qualify as "majority > n/3"

        for(int i = 0; i < n; i++) {
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }

        vector<int> ans;
        if(cnt1 >= mini) ans.push_back(ele1);
        if(cnt2 >= mini) ans.push_back(ele2);

        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,2,1,3,1,1,3,1,1};

    /*
    The Solution::majorityElement function implements an extended version of Moore's Voting Algorithm
     to find all elements in a given vector nums that appear more than ⌊n/3⌋ times, where n is the size of the vector.
     It performs this in two passes: the first identifies up to two potential majority candidates,
      and the second verifies their counts to ensure they meet the threshold.
    */
    sol.majorityElement(nums);
}