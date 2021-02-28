class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        increase = decrease = True
        for i in range(1, len(A)):
            increase = increase and (A[i - 1] <= A[i])
            decrease = decrease and (A[i - 1] >= A[i])
        return increase or decrease
