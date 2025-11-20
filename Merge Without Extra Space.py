class Solution:
    def mergeArrays(self, a, b):
        import math
        n, m = len(a), len(b)
        gap = math.ceil((n + m) / 2)
        while gap > 0:
            i = 0
            j = gap
            while j < n + m:
                if i < n:
                    x = a[i]
                else:
                    x = b[i - n]
                if j < n:
                    y = a[j]
                else:
                    y = b[j - n]
                if x > y:
                    if i < n and j < n:
                        a[i], a[j] = a[j], a[i]
                    elif i < n and j >= n:
                        a[i], b[j - n] = b[j - n], a[i]
                    else:
                        b[i - n], b[j - n] = b[j - n], b[i - n]
                i += 1
                j += 1
            if gap == 1:
                break
            gap = math.ceil(gap / 2)
        return a, b
