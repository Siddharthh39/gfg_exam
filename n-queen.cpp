// User function Template for C++

class Solution {
  public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> res;
        vector<int> curr(n);
        vector<bool> usedRow(n, false);
        vector<bool> deg1(2*n-1, false);
        vector<bool> deg2(2*n-1, false);
        
        backTracking(0, n, curr, usedRow, deg1, deg2, res);
        return res;
    }
    
    void backTracking(int col, int n, vector<int>& curr, vector<bool>& usedRow,
    vector<bool>& deg1, vector<bool>& deg2, vector<vector<int>>& res){
        if(col == n){
            vector<int> solution(n);
            for (int i = 0; i < n; i++){
                solution[i] = curr[i] + 1;
            }
            res.push_back(solution);
        }
        for(int row = 0; row < n; row++){
            if (!usedRow[row] && !deg1[row - col + n-1] && !deg2[row+col]){
                curr[col] = row;
                usedRow[row] = true; deg1[row - col + n-1] = true; deg2[row+col] = true;
                backTracking(col + 1, n, curr, usedRow, deg1, deg2, res);
                
                usedRow[row] = false; deg1[row-col + n-1] = false; deg2[row+col] = false;
            }
        }
    }
    
};
