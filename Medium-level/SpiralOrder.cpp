#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // initialize boundaries
        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        
        vector<int> ans;

        while(top <= bottom && left <= right) {
            // traverse top row
            for(int i = left; i <= right; i++){
                ans.push_back(matrix[top][i]);
            }
            top++;  // top row done, shrink top

            // traverse right column
            for(int i = top; i <= bottom; i++){
                ans.push_back(matrix[i][right]);
            }
            right--;  // right column done, shrink right

            /*
              Check if there are still rows remaining to process the bottom row.
              Example:
              1 2 3
              4 5 6
              (2 rows)

              after top++, top=1, bottom=1
              after right--, right=1
              now you still have a row [4 5 6] to process (bottom row)
              but if matrix was a single row, top might become > bottom,
              then you **must not** process bottom row again.
            */
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;  // bottom row done, shrink bottom
            }

            /*
              Similarly check for columns remaining before processing left column.

              Example:
              1 2
              3 4
              after one pass:
                top=1, bottom=1
                left=0, right=0
              if you do not check left<=right, you might reprocess column 0
              after boundaries cross, so you **must** guard this.
            */
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;  // left column done, shrink left
            }
        }

        return ans;
    }
};
/*
🔍 Summary of those examples in words:
✅ if(top <= bottom)

prevents reading rows that no longer exist after you have shrunk top/bottom

especially happens in single-row or thin rectangles

e.g. 1 2 3 4

✅ if(left <= right)

prevents reading columns that no longer exist after you have shrunk left/right

especially happens in single-column or tall rectangles

e.g.
1
2
3
4
*/
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    vector<int> result = sol.spiralOrder(matrix);
    
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}