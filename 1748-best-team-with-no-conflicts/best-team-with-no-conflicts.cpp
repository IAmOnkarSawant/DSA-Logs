class Solution {
public:
    int findRec(vector<pair<int, int>>& temp, int i, int greater_val, vector<vector<int>>&dp )
    {
        if(i == temp.size())
            return 0;
        
        if(greater_val != -1 && dp[i][greater_val] != -1)
            return dp[i][greater_val];

        int n_take = findRec(temp, i+1, greater_val, dp);
        int take = 0;
        if(greater_val == -1 || temp[i].second >= temp[greater_val].second)
        {
            take = temp[i].second + findRec(temp, i+1, i, dp);
        }
        if(greater_val != -1)
            dp[i][greater_val] = max(take, n_take);
        return max(take, n_take);

    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> temp;
        vector<vector<int>>dp (n, vector<int>(n+5, -1));
        for(int i = 0; i < n; i++)
        {
            temp.push_back({ ages[i], scores[i]});
        }
        sort(temp.begin(), temp.end());
        return findRec(temp, 0, -1, dp);
    }
};