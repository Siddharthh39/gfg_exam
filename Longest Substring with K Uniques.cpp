class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        if (k == 0) return -1;
        int n = (int)s.size();
        if (k > n) return -1;

        vector<int> freq(256, 0); 
        int distinct = 0;
        int left = 0;
        int best = -1;

        for (int right = 0; right < n; ++right) {
            unsigned char c = s[right];
            if (freq[c] == 0) distinct++;
            freq[c]++;

            while (distinct > k) {
                unsigned char cl = s[left];
                freq[cl]--;
                if (freq[cl] == 0) distinct--;
                left++;
            }

            if (distinct == k) {
                best = max(best, right - left + 1);
            }
        }
        return best;
    }
};
