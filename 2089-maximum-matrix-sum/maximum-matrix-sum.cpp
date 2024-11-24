class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans =0;
        long long mini = INT_MAX;
        int n = matrix.size();
        int m = matrix[0].size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(matrix[i][j] < 0)
                {
                    cnt++;
                }
                ans += abs(matrix[i][j]);
                mini = min(mini, (long long)abs(matrix[i][j]));
            }
        }
        // cout<<ans<<" "<<cnt<<" "<<mini<<"\n";
        if(cnt%2)
            return ans - 2*mini;
        return ans;
    }
};