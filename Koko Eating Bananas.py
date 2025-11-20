class Solution:
    def kokoEat(self, arr, k):
        low, high = 1, max(arr)
        def can(s):
            h = 0
            for x in arr:
                h += (x + s - 1) // s
                if h > k:
                    return False
            return True
        ans = high
        while low <= high:
            mid = (low + high) // 2
            if can(mid):
                ans = mid
                high = mid - 1
            else:
                low = mid + 1
        return ans
