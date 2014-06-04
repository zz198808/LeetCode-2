class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            dp[0] = 1;
            dp[i] = 1;
            for (int j = i - 1; j >= 1; j--) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp;
    }
};
