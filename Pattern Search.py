class Solution:
    def search(self, p, s):
        M = len(p)
        N = len(s)
        if M > N:
            return False

        lps = [0] * M
        length = 0
        i = 1
        while i < M:
            if p[i] == p[length]:
                length += 1
                lps[i] = length
                i += 1
            else:
                if length != 0:
                    length = lps[length - 1]
                else:
                    lps[i] = 0
                    i += 1

        i = 0
        j = 0
        while i < N:
            if p[j] == s[i]:
                i += 1
                j += 1
            if j == M:
                return True
            if i < N and p[j] != s[i]:
                if j != 0:
                    j = lps[j - 1]
                else:
                    i += 1

        return False
