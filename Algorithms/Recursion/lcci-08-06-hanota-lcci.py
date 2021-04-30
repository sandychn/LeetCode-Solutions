class Solution:
    def hanota(self, A: List[int], B: List[int], C: List[int]) -> None:
        """
        Do not return anything, modify C in-place instead.
        """
        def helper(src: List[int], dest: List[int], temporary: List[int], count: int) -> None:
            if count == 1:
                dest.append(src.pop())
            else:
                helper(src, temporary, dest, count - 1)
                dest.append(src.pop())
                helper(temporary, dest, src, count - 1)

        helper(A, C, B, len(A))
