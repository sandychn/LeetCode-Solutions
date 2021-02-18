class Solution:
    def longestOnes(self, A: List[int], K: int) -> int:
        zeroCount = left = right = ans = 0
        while right < len(A):
            zeroCount += (1 - A[right])
            # (left <= right) is not necessary in the while condition
            # because (left <= right) will also meet zeroCount > K
            while zeroCount > K:
                zeroCount -= (1 - A[left])
                left += 1
            if zeroCount <= K:
                ans = max(ans, right - left + 1)
            right += 1
        return ans
