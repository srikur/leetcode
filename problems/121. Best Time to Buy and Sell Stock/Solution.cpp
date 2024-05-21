class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyIndex = 0, maxProfit = 0;
        for (size_t i = 0; i < prices.size(); i++) {
            if (prices[i] < prices[buyIndex]) buyIndex = i;
            maxProfit = max(prices[i] - prices[buyIndex], maxProfit);
        }

        return maxProfit > 0 ? maxProfit : 0;
    }
};