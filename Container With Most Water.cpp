class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int holdWater = 0;
        int left = 0; int right = arr.size()-1;
        
        while (left<right){
            int width = right - left;
            int currH = min(arr[left], arr[right]);
            int currA = width * currH;
            
            holdWater = max(holdWater, currA);
            
            if(arr[left] < arr [right]) left++;
            else right--;
        }
        return holdWater;
    }
};
