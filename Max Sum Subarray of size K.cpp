class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        if (n < k) return 0;
        
        int maxSum = 0;
        
        for (int i = 0; i < k; i++){
            maxSum = maxSum + arr[i];
        }
        int winSum = maxSum;
        for (int i = k; i < n; ++i){
            winSum += arr[i] - arr[i - k];
            maxSum = max(maxSum, winSum);
        }
        
        return maxSum;
    }
};
