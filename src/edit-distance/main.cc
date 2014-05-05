class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        vector<vector<int> > dp(n + 2, vector<int> (m + 2, n + m));
        
        dp[0][0] = 0;
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i < n && j < m && word1[i] == word2[j]) {
                    choose_min(dp[i + 1][j + 1], dp[i][j]);
                } 
                choose_min(dp[i + 1][j + 1], dp[i][j] + 1);
                choose_min(dp[i + 1][j], dp[i][j] + 1);
                choose_min(dp[i][j + 1], dp[i][j] + 1);
                
            }
        }
        
        return dp[n][m];
    }
private:
    void choose_min(int &dp, int val) 
    {
        dp = min(dp, val);
    }
};
