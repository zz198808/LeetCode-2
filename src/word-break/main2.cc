/*
 * slow than main.cc, for dp[i] will be multi update to true
 */

class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < n; i++) {
            if (dp[i]) {
                string t;
                for (int j = i; j < n; j++) {
                    t += s[j];
                    if (dict.find(t) != dict.end()) {
                        dp[j + 1] = true;
                    }
                }
            }
        }
        
        return dp[n];
    }
    
};
