class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        vector<vector<int> > dp(n + 1);
        dp[n].push_back(-1);
        
        for (int i = n - 1; i >= 0; i--) {
            string t;
            for (int j = i + 1; j <= n; j++) {
                t += s[j - 1];
                if (dp[j].size() > 0 && dict.find(t) != dict.end()) {
                    dp[i].push_back(j);
                }
            }
        }
        vector<string> ans;
        
        output(ans, dp, s, "", 0, n);
        
        return ans;
        
    }
private:
    void output(vector<string> &ans, const vector<vector<int> > &dp, const string &s, const string &t, int cur, int n) {
        if (cur >= n) {
            ans.push_back(t);
            return;
        }
      
        string t1 = t;
        
        if (cur != 0) {
            t1 += ' ';
        }
        
        for (int j = 0; j < dp[cur].size(); j++) {
            
            output(ans, dp, s, t1 + s.substr(cur, dp[cur][j] - cur), dp[cur][j], n);
        }
    }
};
