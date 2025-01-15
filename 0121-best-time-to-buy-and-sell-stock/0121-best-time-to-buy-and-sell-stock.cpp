class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int buy = INT_MAX;
        for(int i=0; i<n; i++) {
            buy = min(prices[i], buy);//1
            int sell = prices[i];//1
            maxProfit = max(maxProfit, sell-buy);
        }
        return maxProfit;
    }
};