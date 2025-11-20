class Solution:
    def removeDuplicates(self, arr):
        # code here 
        store = list(set(arr))
        return sorted(store)
