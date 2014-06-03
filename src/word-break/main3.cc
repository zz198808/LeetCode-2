/*
 * O(N * (M * MLen))
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        
        for (int i = n - 1; i >= 0; i--) {
            for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); ++it) {
                if (it->size() + i <= n) {
                    if (dp[it->size() + i]) {
                        bool ok = true;
                        for (int j = i; j < i + it->size(); j++) {
                            if (s[j] != (*it)[j - i]) {
                                ok = false;
                                break;
                            }
                        }
                        if (ok) {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
        }
        
       
        
        return dp[0];
    }
    
};
