class Solution {
public:
    int findRec(int i, int j, string s1, string s2, vector<vector<int>>&dp)
    {
        if(j < 0 )
            return i+1;
        if(i < 0)
            return j+1;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        // cout<<"("<<i<<","<<j<<") => "<<s1[i]<<" "<<s2[j]<<"\n";
        if(s1[i] == s2[j])
        {
            return dp[i][j] = findRec(i-1, j-1, s1, s2, dp);
        }
        int insert = findRec(i, j-1, s1,s2, dp) + 1;
        int deletee = findRec(i-1, j, s1,s2, dp) + 1;
        int replace = findRec(i-1, j-1, s1,s2, dp) + 1;
        return dp[i][j] = min(insert, min(deletee, replace));
    }

    int minDistance(string word1, string word2) 
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return findRec(n-1, m-1, word1, word2, dp);
    }
};