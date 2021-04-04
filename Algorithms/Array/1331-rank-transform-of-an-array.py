class Solution:
    def arrayRankTransform(self, arr: List[int]) -> List[int]:
        ordered = sorted(set(arr))
        return [bisect.bisect_left(ordered, v) + 1 for v in arr]
