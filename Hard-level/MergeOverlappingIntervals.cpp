#include <bits/stdc++.h>
using namespace std;

class Solution
{
    /*
    🧠 Intuition Behind the Problem:
Goal: Merge all overlapping intervals.

Key Idea:
If intervals overlap (next_start <= current_end), merge them by extending the end.
Sorting makes sure overlapping intervals come next to each other, so you only need to merge consecutive ones.

⏱️ Time Complexity:
Step	                    Time
Sorting intervals	    O(N log N)
Outer loop	            O(N)
Inner loop (worst case)	O(N) — nested traversal if many overlaps

➡️ Overall: O(N²) in the worst case, due to the nested loop.
    */
public:
    // APPROACH 1
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        // ✅ Step 1: Sort the intervals based on the start time
        // This is **critical** to simplify merging:
        // After sorting, all overlapping intervals will be adjacent
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        // ✅ Step 2: Iterate through the intervals one by one
        for (int i = 0; i < n; i++)
        {
            int start = intervals[i][0]; // current interval start
            int end = intervals[i][1];   // current interval end

            /*
              ✅ Optimization:
              If the current interval is already fully merged into the last
              element in 'ans' (i.e., end is not extending beyond the previous merged interval),
              we can skip it to avoid redundant work.
            */
            if (!ans.empty() && end <= ans.back()[1])
                continue;

            /*
              ✅ Step 3: Try to merge current interval with all overlapping ones ahead
              As long as the next interval starts before or at 'end',
              we extend the 'end' to cover the max of both.
            */
            for (int j = i + 1; j < n; j++)
            {
                if (intervals[j][0] <= end)
                {
                    // Overlap exists, extend the current interval
                    end = max(end, intervals[j][1]);
                }
            }

            // ✅ Step 4: Push the merged interval to the answer
            ans.push_back({start, end});
        }

        return ans;
    }

    // APPROACH 2- BETTER
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;

        // ✅ Step 1: Sort intervals based on starting point
        // This ensures that overlapping intervals are next to each other
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();

        // ✅ Step 2: Traverse all intervals
        for (int i = 0; i < n; i++)
        {

            /*
              ✅ Case 1: If 'ans' is empty OR there is **no overlap**
              (i.e., last merged interval ends before current starts),
              then simply add the current interval
            */
            if (ans.empty() || ans.back()[1] < intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                /*
                  ✅ Case 2: Overlap exists → merge the intervals
                  - Take the current interval
                  - Compare its end with the last interval in ans
                  - Update the last interval’s end with the maximum value
                */
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    };
