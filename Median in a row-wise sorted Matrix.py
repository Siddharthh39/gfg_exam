class Solution:
    def median(self, mat):
        n = len(mat)
        m = len(mat[0])
        
        # Minimum element of matrix = min of first column
        low = min(row[0] for row in mat)
        # Maximum element = max of last column
        high = max(row[-1] for row in mat)

        desired = (n * m + 1) // 2   # position of median

        # Binary search in the value space
        while low < high:
            mid = (low + high) // 2

            # Count how many numbers <= mid
            count = 0
            for row in mat:
                # Each row is sorted → binary search within row
                # bisect_right gives count of elements <= mid
                import bisect
                count += bisect.bisect_right(row, mid)

            if count < desired:
                low = mid + 1
            else:
                high = mid

        return low

        
