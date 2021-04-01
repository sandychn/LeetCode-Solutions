class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        l, r = 0, len(height) - 1
        lMax = rMax = 0
        while l < r:
            lMax = max(lMax, height[l])
            rMax = max(rMax, height[r])
            if height[l] < height[r]:
                ans += lMax - height[l]
                l += 1
            else:
                ans += rMax - height[r]
                r -= 1
        return ans
