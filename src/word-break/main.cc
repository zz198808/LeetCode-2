/*
 * O(N^2logM)
 */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = false;
            string t;
            for (int j = i + 1; j <= n; j++) {
                t += s[j - 1];
                if (dp[j]) {
                    if (dict.find(t) != dict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[0];
    }
    
};
