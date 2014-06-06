class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0)
            return 0;
        vector<int> dp(s.size() + 1, 0);
        
        dp[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i - 1] >= '1' && s[i - 1] <= '9') {
                dp[i] += dp[i - 1];
            }
            if (i >= 2) {
                int d = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (d >= 10 && d <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        
        return dp[s.size()];
        
    }
};
