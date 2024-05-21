class Solution {
    public int maxProfit(int[] prices) {
        int buyIndex = 0, profit = 0;
        for (int i = 0; i < prices.length; i++) {
            if (prices[i] < prices[buyIndex]) buyIndex = i;
            profit = Math.max(profit, prices[i] - prices[buyIndex]);
        }
        return profit > 0 ? profit : 0;
    }
}