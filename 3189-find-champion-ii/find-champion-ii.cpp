 #include <queue>
class Solution {
public:
   
int detectCycleInDirectedGraph(int n, vector < vector < int >> & edges) 
{
   
    vector<int>adj[n+1];
    for(int i = 0; i < edges.size(); i++)
    {
      adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int>inD(n+1, 0);
        for(int i = 0; i < n+1; i++)
            for( auto it: adj[i])
                inD[it]++;
        
        queue<int>q;
        for(int i = 0; i < n+1; i++)
            if(inD[i] == 0)
                q.push(i);
           
        int ans = 0;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
          ans++;
            
            for(auto it : adj[f])
            {
                inD[it]--;
                if(inD[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        if(ans < n)
        return 1;
      return 0;
}
    int findChampion(int n, vector<vector<int>>& edges) {
        if(detectCycleInDirectedGraph(n, edges))
        {
            return -1;
        }
        vector<int>inD(n, 0);
        for(int i = 0; i < edges.size(); i++)
        {
           inD[edges[i][1]]++;
        }
        int ans = 0;
        int t = 0;
        for(int i = 0; i < n; i++)
        {
            if(inD[i] == 0)
            {
                t = i;
                ans++;
            }
                
            if(ans > 1)
                return -1;
        }
        return t;
    }
};