class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) 
    {
        vector<vector<int>> adj{{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
        string curr = "";
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 3; j++)
                curr+= to_string(board[i][j]);
        unordered_set<string> visited;
        string final_string  = "123450";
        queue<pair<string, int>>q;
        q.push({curr,0});
        visited.insert(curr);
        while(!q.empty())
        {
            string s = q.front().first;
            int moves = q.front().second;
            q.pop();
            // cout<<s<<"--\n";
            if(s == final_string)
            {
                return moves;
            }

            int pos = s.find('0');
            // cout<<pos<<"\n";
            for(auto it: adj[pos])
            {
                string temp = s;
                // cout<<temp<<"\n";
                swap(temp[it], temp[pos]);
                // cout<<temp<<"\n";
                if(visited.count(temp) == 0)
                {
                    visited.insert(temp);
                    q.push({temp, moves+1});
                }
            }
        }
        return -1;
    }

/*
00 01 02
10 11 12

0 1 2 3 4 5 

0 = 1 3
1 = 0 2 4
2 = 1 5 
3 = 0 4
4 = 3 1 5
5 = 2 4  

*/
};