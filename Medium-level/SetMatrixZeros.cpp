#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        /*
          Instead of taking extra arrays to mark rows and columns,
          we use the first row and first column of the matrix itself
          to store these markers:
          - mat[i][0] marks whether the i-th row should be zeroed
          - mat[0][j] marks whether the j-th column should be zeroed
          
          BUT:
          - mat[0][0] is shared by first row and first column
          - so we take an extra variable `col0` to separately track first column zero state
        */
        bool col0 = false;
        
        // first pass to mark zeros in the first row/column
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    // mark row
                    mat[i][0] = 0;

                    if(j != 0){
                        // mark column (except first column)
                        mat[0][j] = 0;
                    }
                    else{
                        // separately track if first column needs to be zero
                        col0 = true;
                    }
                }
            }
        }
        
        /*
          second pass to set elements to zero based on markers
          except first row and first column
        */
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(mat[i][0] == 0 || mat[0][j] == 0)
                    mat[i][j] = 0;
            }
        }
        
        /*
          now handle the first row
          (if mat[0][0] == 0, that means first row had a zero originally)
        */
        if(mat[0][0] == 0){
            for(int j = 0; j < m; j++){
                mat[0][j] = 0;
            }
        }
        
        /*
          finally handle the first column based on col0
        */
        if(col0){
            for(int i = 0; i < n; i++){
                mat[i][0] = 0;
            }
        }
    }
};
int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    
    sol.setMatrixZeroes(matrix);
    
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}