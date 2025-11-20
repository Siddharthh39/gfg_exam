class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int count = 0;
        int i = 0;
        
        while (i < arr.size()){
            if (arr[i] == 0){
                arr.erase(arr.begin() + i);
                count++;
            }
            else{
                i++;
            }
        }
        while (count--){
            arr.push_back(0);
        }
    }
};
