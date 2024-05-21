class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = 0
        profit = 0
        for ind, i in enumerate(prices):
            profit = max(profit, i - prices[buy])
            if i < prices[buy]:
                buy = ind
        return profit if profit > 0 else 0