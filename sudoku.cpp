class Solution {
  public:
    // Function to find a solved Sudoku.
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat);
    }
    
    bool solve(vector<vector<int>>& mat){
        int row = -1; int col = -1;
        bool isEmpty = false;
        
        for(int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (mat[i][j] == 0){
                    row = i; col = j;
                    isEmpty = true;
                    break;
                }
            }
            if (isEmpty) break;
        }
        if (!isEmpty) return true;
        
        for (int num = 1; num <= 9; num++ ){
            if(isValid(mat, row, col, num)){
                mat[row][col] = num;
                if (solve(mat)) return true;
                mat[row][col] = 0;
            }
        }
        return false;
    }
    
    bool isValid(const vector<vector<int>>& mat, int row, int col, int num){
        for(int j = 0; j < 9; j++){
            if (mat[row][j] == num){
                return false;
            }
        }
        for(int i = 0; i < 9; i++){
            if (mat[i][col] == num){
                return false;
            }
        }
        int showRow = row - row % 3;
        int showCol = col - col % 3;
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(mat[showRow + i][showCol + j]==num){
                    return false;
                }
            }
        }
        return true;
    }
};
