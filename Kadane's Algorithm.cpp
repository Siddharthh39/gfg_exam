class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int crrSum = arr[0];
        int maxSum = arr[0];
        
        for (int i = 1; i < arr.size(); i++){
            crrSum = max(arr[i], crrSum + arr[i]);
            maxSum = max(maxSum, crrSum);
        }
        return maxSum;
    }
};
