class Solution:
    def mergeThree(self, a, b, c):
        i = j = k = 0
        n, m, p = len(a), len(b), len(c)
        res = []
        while i < n or j < m or k < p:
            x = a[i] if i < n else float('inf')
            y = b[j] if j < m else float('inf')
            z = c[k] if k < p else float('inf')
            if x <= y and x <= z:
                res.append(x)
                i += 1
            elif y <= x and y <= z:
                res.append(y)
                j += 1
            else:
                res.append(z)
                k += 1
        return res
