class Solution:
    def findPages(self, arr, k):
        n = len(arr)
        if k > n:
            return -1

        low = max(arr)
        high = sum(arr)

        def can(mid):
            s = 1
            pages = 0
            for x in arr:
                if pages + x > mid:
                    s += 1
                    pages = x
                    if s > k:
                        return False
                else:
                    pages += x
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
