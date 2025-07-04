#include<bits/stdc++.h>
using namespace std;

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

class Solution {
public:
    // Function to find the length of the longest consecutive sequence in an unsorted array
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0; // If array is empty, return 0

        int longest = INT_MIN; // To keep track of the longest sequence found
        unordered_set<int> st; // Use a set for O(1) lookups and to remove duplicates

        // Insert all elements into the set
        for (int i = 0; i < n; i++)
            st.insert(nums[i]);

        // Iterate through each unique element in the set
        for (auto it : st) {
            // Check if 'it' is the start of a sequence
            if (st.find(it - 1) == st.end()) {
                int cnt = 1; // Current sequence length
                int x = it;
                // Count consecutive numbers starting from 'it'
                while (st.find(x + 1) != st.end()) {
                    cnt++;
                    x = x + 1;
                }
                longest = max(longest, cnt); // Update the longest sequence length
            }
        }

        return longest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    int result = sol.longestConsecutive(nums);
    
    cout << "Length of the longest consecutive sequence: " << result << endl;

    return 0;
}