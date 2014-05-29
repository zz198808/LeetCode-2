class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() == 0)
            return 0;
        int n = prices.size();
        vector<int> tran1(n), tran2(n);
        int minv = prices[0];
        tran1[0] = 0;
        for (int i = 1; i < n; i++) {
            tran1[i] = max(tran1[i - 1], prices[i] - minv);
            minv = min(minv, prices[i]);
        }
        
        int maxv = prices[n - 1];
        tran2[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            tran2[i] = max(tran2[i + 1], maxv - prices[i]);
            maxv = max(maxv, prices[i]);
        }
        
        int ans = max(tran1[n - 1], tran2[0]);
        for (int i = 1; i < n; i++) {
            ans = max(ans, tran1[i - 1] + tran2[i]);
        }
        return ans;
    }

};
