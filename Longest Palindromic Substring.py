class Solution:
    def getLongestPal(self, s):
        n = len(s)
        if n < 2:
            return s

        start = 0
        max_len = 1

        def expand(l, r):
            nonlocal start, max_len
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 > max_len:
                    max_len = r - l + 1
                    start = l
                l -= 1
                r += 1

        for i in range(n):
            expand(i, i)
            expand(i, i + 1)

        return s[start:start + max_len]
