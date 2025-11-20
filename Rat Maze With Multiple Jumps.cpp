class Solution {
  public:
    bool isSafe(int a, int b, int n, vector<vector<int>>& maze){
        return (a >= 0 && a <n && b >= 0 && b < n && maze[a][b] > 0);
    }
    
    bool solveMaze(int a, int b, int n, vector<vector<int>>& maze, vector<vector<int>>& sol){
        if(a == n - 1 && b == n-1){
            sol[a][b] = 1; return true;
        }
        if (isSafe(a,b,n,maze)){
            sol[a][b] = 1;
            int maxJump = maze[a][b];
            
            for(int i = 1; i <= maxJump; i++){
                if(solveMaze(a,b+i,n,maze,sol)) return true;
                if (solveMaze(a+i,b,n,maze,sol)) return true;
            }
            
            sol[a][b] = 0;
        }
        return false;
    }

    vector<vector<int>> solve(int n, vector<vector<int>>& maze) {
        // code here
        vector<vector<int>> sol(n, vector<int>(n, 0));
        if (!solveMaze(0,0,n,maze,sol)) return {{-1}};
        return sol;
    }
};
