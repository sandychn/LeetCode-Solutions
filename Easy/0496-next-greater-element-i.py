class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        next_larger_value = [-1] * 10001
        stack = []
        for v in nums2:
            while stack and stack[-1] < v:
                next_larger_value[stack.pop()] = v
            stack.append(v)
        return [next_larger_value[v] for v in nums1]
