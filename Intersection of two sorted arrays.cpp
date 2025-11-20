class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int> arr;
        int i = 0; int j = 0;
        
        while(i < arr1.size() && j < arr2.size()){
            if(arr1[i] == arr2[j]){
                if(arr.empty() || arr.back() != arr1[i]){
                    arr.push_back(arr1[i]);
                }
            i++; j++;
            }
            else if(arr1[i] < arr2[j]) i++;
            else j++;
        }
        return arr;
        
        
    }
};
