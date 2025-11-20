class Solution:
    def search(self, txt, pat):
        s = pat + "$" + txt
        n = len(s)
        Z = [0] * n
        l = r = 0
        for i in range(1, n):
            if i <= r:
                Z[i] = min(r - i + 1, Z[i - l])
            while i + Z[i] < n and s[Z[i]] == s[i + Z[i]]:
                Z[i] += 1
            if i + Z[i] - 1 > r:
                l, r = i, i + Z[i] - 1
        m = len(pat)
        res = []
        for i in range(n):
            if Z[i] == m:
                res.append(i - m - 1)
        return res
