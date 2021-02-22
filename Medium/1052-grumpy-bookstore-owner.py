class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], X: int) -> int:
        all_cnt = sum(c * (g ^ 1) for c, g in zip(customers, grumpy))
        become_satisfied_cnt = sum(c * g for c, g in zip(customers[:X], grumpy[:X]))
        ans = all_cnt + become_satisfied_cnt
        right = X
        while right < len(customers):
            become_satisfied_cnt -= customers[right - X] * grumpy[right - X]
            become_satisfied_cnt += customers[right] * grumpy[right]
            ans = max(ans, all_cnt + become_satisfied_cnt)
            right += 1
        return ans
