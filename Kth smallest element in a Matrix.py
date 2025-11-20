class Solution:
    def kthSmallest(self, mat, k):
        import heapq
        n = len(mat)
        heap = [(mat[0][0], 0, 0)]
        visited = {(0,0)}
        while k:
            val, r, c = heapq.heappop(heap)
            k -= 1
            if k == 0:
                return val
            if r+1 < n and (r+1, c) not in visited:
                visited.add((r+1, c))
                heapq.heappush(heap, (mat[r+1][c], r+1, c))
            if c+1 < n and (r, c+1) not in visited:
                visited.add((r, c+1))
                heapq.heappush(heap, (mat[r][c+1], r, c+1))
