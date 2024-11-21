class Solution {
public:
    /*
        1 - unguarded cell
        0 - blocked
        -1 - wall
        2 - guard
    */
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>pos(m, vector<int>(n, 1));
        for(auto pair: walls)
        {
            int i = pair[0];
            int j = pair[1];

            pos[i][j] = -1;
        }
        for(auto g: guards)
        {
            int gi = g[0];
            int gj = g[1];
            pos[gi][gj] = 2;
        }

        for(int gi = 0; gi < m; gi++)
        {
            for(int gj = 0; gj < n; gj++)
            {
                if(pos[gi][gj] == 2)
                {
                     for(int i = gi-1; i >= 0 ; i--)
                    {
                        if(pos[i][gj] == -1 || pos[i][gj] == 2)
                            break;
                        pos[i][gj] = 0;
                    }
                    for(int i = gi+1; i < m ; i++)
                    {
                        if(pos[i][gj] == -1 || pos[i][gj] == 2)
                            break;
                        pos[i][gj] = 0;
                    }
                    for(int i = gj-1; i >= 0 ; i--)
                    {
                        if(pos[gi][i] == -1 || pos[gi][i] == 2)
                            break;
                        pos[gi][i] = 0;
                    }
                    for(int i = gj+1; i < n ; i++)
                    {
                        if(pos[gi][i] == -1 || pos[gi][i] == 2)
                            break;
                        pos[gi][i] = 0;
                    }
                }

            }
        }
       
        int cnt = 0;
        for(auto vec: pos)
        {
            for(auto ele: vec)
            {
                // cout<<ele<<" ";
                if(ele == 1)
                    cnt++;
            }
            // cout<<"\n";
        }
        return cnt;
    }
};