class Solution {
public:
    int lps(string& s, int i, int j, vector<vector<int>>&dp)
    {
        if(i >= s.size() || j < 0 || i > j)
        {
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s[i] == s[j])
        {
            int to_add = 2;
            if(i == j)
                to_add = 1;
            return dp[i][j] = (lps(s, i+1, j-1, dp) + to_add);
        }
        int a = lps(s, i+1, j, dp);
        int b = lps(s, i, j-1, dp);
        return dp[i][j] = max(a, b);
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,  vector<int>(n, -1));
        return lps(s, 0, n-1, dp);
    }
};