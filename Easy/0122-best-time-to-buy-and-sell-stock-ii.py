class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices:
            return 0
        buyPrice = prices[0]
        ans = 0
        for price in prices:
            if buyPrice < price:
                ans += price - buyPrice
            buyPrice = price
        return ans
