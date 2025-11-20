class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        int first = -1, last = -1;

        int left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] < x) {
                left = mid + 1;
            } else if(arr[mid] > x) {
                right = mid - 1;
            } else {
                first = mid;
                right = mid - 1; 
            }
        }
        
        left = 0, right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] < x) {
                left = mid + 1;
            } else if(arr[mid] > x) {
                right = mid - 1;
            } else {
                last = mid;
                left = mid + 1; 
            }
        }
        
        return {first, last};
    }
};
