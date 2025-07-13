#include<bits/stdc++.h>

//APPROACH 1
/*
🧠 Key Concepts to Remember:
===>Why both maxCurr and minCurr?
A negative number can flip the product:

max × negative → min min × negative → max
Hence, always track both the max and min product at each index.

===>What does maxCurr track?
The maximum product of subarray ending at index i
Why store temp?
minCurr uses the original maxCurr before it's updated.
Why use max({a, b, c})?
At each index, three cases:

1.Start a new subarray with nums[i] 
2.Extend previous max product 
3.Extend previous min product
Time and Space Complexity
Time: O(n) Space: O(1)
===>When to reset?
We never manually reset, because taking nums[i] alone handles the reset automatically.

*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Edge cases
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];

        // Initialize current max, min, and overall max with the first element
        int maxCurr = nums[0];
        int minCurr = nums[0];
        int maxSofar = nums[0];

        // Traverse the array from second element onwards
        for(int i = 1; i < nums.size(); i++){
            int temp = maxCurr;  // Store current max because it will be overwritten

            // Update current max product ending at index i
            // Either:
            // - Start fresh from nums[i]
            // - Extend previous max product
            // - Extend previous min product (if nums[i] is negative)
            maxCurr = max({nums[i], maxCurr * nums[i], minCurr * nums[i]});

            // Update current min product ending at index i
            // This is needed because a negative * negative = positive
            minCurr = min({nums[i], temp * nums[i], minCurr * nums[i]});

            // Update global max if needed
            maxSofar = max(maxSofar, maxCurr);
        }

        return maxSofar;
    }
};


//APPROACH 2
class Solution {
public:
    /*
     Concept Recap in Simple Points (Put this in your notes):
        This approach works because:
        ->The product may flip sign with negatives, and even negatives can make a product large.
        ->Multiplying from both ends helps catch max products on both sides.
        Zeros break the product chain — we reset prefix and suffix when they hit 0.
        It avoids tracking minProduct, unlike Kadane’s variant.
    */
    int maxProduct(vector<int>& nums) {
        // 'prefix' holds product from left to right
        // 'suffix' holds product from right to left
        int prefix = 1;
        int suffix = 1;

        // Initialize answer with the smallest possible value
        int ans = INT_MIN;

        int n = nums.size();

        // Traverse the array once, but from both directions simultaneously
        for(int i = 0; i < n; i++) {
            // Reset prefix product if it becomes 0 (zero breaks the subarray chain)
            if(prefix == 0) prefix = 1;

            // Reset suffix product if it becomes 0
            if(suffix == 0) suffix = 1;

            // Multiply current number from the front (prefix product)
            prefix *= nums[i];

            // Multiply current number from the back (suffix product)
            suffix *= nums[n - i - 1];

            // Update maximum product found so far
            ans = max({ans, prefix, suffix});
        }

        // Final maximum product subarray value
        return ans;
    }
};

