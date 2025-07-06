#include<bits/stdc++.h>
using namespace std;

/*
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Explanation:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<int> generateRow(int row){
        long long ans = 1;       // nC0 is always 1
        vector<int> ansRow;
        ansRow.push_back(1);     // first element in every row is 1

        /*
          We will now generate elements from nC1 to nC(row-1)
          using the property:
          nC(r+1) = nCr * (n-r)/(r+1)

          Example:
          row = 5
          elements:
            5C0 = 1
            5C1 = 5C0 * (5-1)/1  = 1*4/1 = 4
            5C2 = 5C1 * (5-2)/2  = 4*3/2 = 6
            5C3 = 5C2 * (5-3)/3  = 6*2/3 = 4
            5C4 = 5C3 * (5-4)/4  = 4*1/4 = 1
        */
        for(int col = 1; col < row; col++){
            ans = ans * (row - col);   // nCr * (n-r)
            ans = ans / (col);         // divide by r to finish formula
            ansRow.push_back(ans);     // push nCr
        }

        return ansRow;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        /*
          Now generate all rows 1 to numRows
          Example:
          numRows = 5
          rows:
          row1: 1
          row2: 1 1
          row3: 1 2 1
          row4: 1 3 3 1
          row5: 1 4 6 4 1
        */
        for(int i = 1; i <= numRows; i++){
            ans.push_back(generateRow(i));
        }

        return ans;
    }
};
/*
      We will build each row one by one:

      numRows = 5
      so i goes 1 to 5
      i = row length

      ---------
      i=1
      generateRow(1):
        only 1 element:
          [1]
      ans = [[1]]

      ---------
      i=2
      generateRow(2):
        start with 1
        col=1:
          ans = ans * (2-1)/1 = 1*1/1 = 1
        row = [1,1]
      ans = [[1], [1,1]]

      ---------
      i=3
      generateRow(3):
        start with 1
        col=1:
          ans = 1 * (3-1)/1 = 1*2/1=2
        col=2:
          ans = 2 * (3-2)/2= 2*1/2=1
        row = [1,2,1]
      ans = [[1],[1,1],[1,2,1]]

      ---------
      i=4
      generateRow(4):
        start with 1
        col=1:
          ans = 1*(4-1)/1= 3/1=3
        col=2:
          ans = 3*(4-2)/2=3*2/2=3
        col=3:
          ans = 3*(4-3)/3=3*1/3=1
        row = [1,3,3,1]
      ans = [[1],[1,1],[1,2,1],[1,3,3,1]]

      ---------
      i=5
      generateRow(5):
        start with 1
        col=1:
          ans= 1*(5-1)/1=4/1=4
        col=2:
          ans=4*(5-2)/2=4*3/2=6
        col=3:
          ans=6*(5-3)/3=6*2/3=4
        col=4:
          ans=4*(5-4)/4=4*1/4=1
        row = [1,4,6,4,1]
      ans = [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

    */

//Time Complexity: O(n^2) where n is numRows, since we generate each row in O(n) time and there are numRows rows.
    //Space Complexity: O(n^2) for storing the result.

int main() {
    Solution sol;   
    int numRows = 5;
    vector<vector<int>> result = sol.generate(numRows);
    for (const auto& row : result) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}