class Solution:

    arr = []

    def tribonacci(self, n: int) -> int:
        arr = Solution.arr
        if not arr:
            arr = [0] * 38
            arr[:3] = [0, 1, 1]
            for i in range(3, 38):
                arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3]
        return arr[n]
