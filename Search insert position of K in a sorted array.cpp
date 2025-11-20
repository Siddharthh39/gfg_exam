class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        //code here
        int left = 0, right = arr.size() - 1;
        int ans = arr.size(); 
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == k) {
                return mid;
            } 
        
            else if (arr[mid] < k) {
                left = mid + 1;
            } 
        
            else {
                ans = mid;
                right = mid - 1;
            }
        }
        return ans;
    }
};
