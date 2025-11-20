// User function Template for C++

class Solution {
  public:
    int findMatching(string text, string pat) {
        // Code here
        int n = text.size();
        int m = pat.size();
        
        for(int i = 0; i <= n-m; i++){
            string window = text.substr(i, m);
            if (window == pat){
                return i;
            }
        }
        return -1;
    }
};
