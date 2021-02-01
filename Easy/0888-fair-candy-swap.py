class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        a_sum = sum(A)
        b_sum = sum(B)
        b_set = set(B)
        for a_val in A:
            # a_sum - a_val + b_val = b_sum - b_val + a_val
            # b_val = (b_sum + a_val + a_val - a_sum) / 2
            # b_val = (b_sum - a_sum + 2 * a_val) / 2
            b_val, remainder = divmod(b_sum - a_sum + 2 * a_val, 2)
            if remainder == 0 and b_val in b_set:
                return [a_val, b_val]
        return []
