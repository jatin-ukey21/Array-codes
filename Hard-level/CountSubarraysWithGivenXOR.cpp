#include<bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

/*
✅ Summary of Approach
Sort the array → ensures we can use two-pointer efficiently

Fix two numbers (i and j) → reduce problem to 2Sum

Use two pointers (k and l) to find the other two numbers

Skip duplicates at all levels to avoid redundant quadruplets

Avoid integer overflow using long long for sum

🧠 Time Complexity
Outer two loops: O(n²)

Inner two-pointer scan: O(n)

Total: O(n³) → acceptable for n ≤ 200–300 range
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Step 1: Sort the array to simplify two-pointer and duplicate handling
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int n = nums.size();

        // Step 2: First loop — fix the first number (i)
        for(int i = 0; i < n; i++) {
            // Skip duplicates for the first number
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: Second loop — fix the second number (j)
            for(int j = i + 1; j < n; j++) {
                // Skip duplicates for the second number
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                // Step 4: Now use two pointers to find the remaining two numbers
                int k = j + 1;      // third pointer
                int l = n - 1;      // fourth pointer

                while(k < l) {
                    // Use long long to prevent integer overflow for large inputs
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum == target) {
                        // Found a valid quadruplet
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        // Skip duplicates for the third number
                        while(k < l && nums[k] == nums[k - 1]) k++;

                        // Skip duplicates for the fourth number
                        while(k < l && nums[l] == nums[l + 1]) l--;
                    }
                    else if(sum < target) {
                        // If sum is too small, increase it by moving left pointer
                        k++;
                    }
                    else {
                        // If sum is too large, decrease it by moving right pointer
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};

/*
🧪 Input:
nums = {1, 0, -1, 0, -2, 2}
target = 0

✅ Output:
Quadruplets that sum to 0:
-2 -1 1 2
-2  0 0 2
-1  0 0 1
🧠 Explanation of Output:
Sorted input: {-2, -1, 0, 0, 1, 2}

-2 + -1 + 1 + 2 = 0

-2 + 0 + 0 + 2 = 0

-1 + 0 + 0 + 1 = 0

Each quadruplet adds up to 0 and is unique (no duplicates).
*/
