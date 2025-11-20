def Rabin_Karp(pat, txt, q):
    m, n = len(pat), len(txt)
    d = 256
    h = pow(d, m-1, q)
    p = 0
    t = 0
    res = []

    for i in range(m):
        p = (p*d + ord(pat[i])) % q
        t = (t*d + ord(txt[i])) % q

    for i in range(n - m + 1):
        if p == t:
            if txt[i:i+m] == pat:
                res.append(i)
        if i < n - m:
            t = (t - ord(txt[i]) * h) % q
            t = (t*d + ord(txt[i+m])) % q
            t = (t + q) % q

    return res
