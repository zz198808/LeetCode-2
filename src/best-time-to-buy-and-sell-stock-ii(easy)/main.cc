class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        
        int buy = prices[0];
        int ans = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < prices[i - 1]) {
                ans += prices[i - 1] - buy;
                buy = prices[i];
            }
        }
        
        ans += *prices.rbegin() - buy;
        
        return ans;
        
    }
};
