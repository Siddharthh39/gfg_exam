class Solution:
    def leastWeightCapacity(self, arr, n, d):
        low, high = max(arr), sum(arr)
        def can(cap):
            days = 1
            cur = 0
            for x in arr:
                if cur + x > cap:
                    days += 1
                    cur = x
                    if days > d:
                        return False
                else:
                    cur += x
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
