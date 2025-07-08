#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // BETTER APPROACH, BUT THROWS TLE ON LEETCODE
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> st; // to store unique triplets without duplicates
        int n = nums.size();

        // Outer loop: fix the first element one by one
        for (int i = 0; i < n; i++)
        {
            set<int>
                hashset; // used to track elements we’ve seen in the inner loop

            // Inner loop: for every nums[i], find two-sum (nums[j] + nums[k]) =
            // -nums[i]
            for (int j = i + 1; j < n; j++)
            {
                int third =
                    -(nums[i] +
                      nums[j]); // the required third number to make the sum 0

                // If the third number was already seen in this inner loop
                if (hashset.find(third) != hashset.end())
                {
                    vector<int> tmp = {nums[i], nums[j], third};
                    sort(tmp.begin(),
                         tmp.end()); // sort triplet to handle duplicate order
                    st.insert(tmp);  // insert into set to automatically remove
                                     // duplicates
                }

                // Record nums[j] for future lookups
                hashset.insert(nums[j]);
            }
        }

        // Convert the set of unique triplets to a vector of vectors to return
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }

    // OPTIMAL APPROACH
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        // Edge case: less than 3 elements can't form a triplet
        if (nums.size() <= 2)
            return {};

        int n = nums.size();
        vector<vector<int>> ans;

        // Step 1: Sort the array to enable two-pointer strategy and easy duplicate skipping
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element (nums[i]) one by one
        for (int i = 0; i < n; i++)
        {
            // Skip duplicate elements for the first position to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1; // Left pointer
            int k = n - 1; // Right pointer

            // Step 3: Use two-pointer approach to find remaining two elements
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum < 0)
                {
                    // Need a larger sum → move left pointer right
                    j++;
                }
                else if (sum > 0)
                {
                    // Need a smaller sum → move right pointer left
                    k--;
                }
                else
                {
                    // Found a triplet with sum 0
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);

                    // Move both pointers and skip duplicates
                    j++;
                    k--;

                    // Skip duplicate values for j (left)
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // Skip duplicate values for k (right)
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        // Final list of unique triplets
        return ans;
    }
};