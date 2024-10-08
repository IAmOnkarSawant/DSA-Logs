#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long L, R, H, S;
    cin>>L>>R>>H>>S;
    unordered_map<string , int>um;
    unordered_set<int>safe_house;
    unordered_map<int , int>h_time;

    for(int i = 0; i < L; i++)
    {
        string s;
        cin>>s;
        um[s] = i;
    }

    vector<vector<int>>adj(L+1);
    for(int i = 0; i < R; i++)
    {
        string u, v;
        cin>>u>>v;
        adj[um[u]].push_back(um[v]);
        adj[um[v]].push_back(um[u]);
    }
    
    //        node, dist
    queue<pair<int, int>> q;
    while(H--)
    {
        string h;
        int t;
        cin>>h>>t;
        h_time[um[h]] = t;
    }

    vector<int> min_dist(L, INT_MAX);
    while(S--)
    {
        string sh;
        cin>>sh;
        safe_house.insert(um[sh]);
        q.push({um[sh], 0});
        min_dist[um[sh]] = 0;
    }
   

    while(q.empty() == 0)
    {
        auto front = q.front();
        int node = front.first;
        int dist = front.second;
        q.pop();
        for(auto it: adj[node])
        {
            if(min_dist[it] == INT_MAX)
            {
                min_dist[it] = dist + 1;
                q.push({it, dist+1});
            }
        }
    }
    int min_time = INT_MAX;
    for(int i = 0; i < L ; i++)
    {
        if(h_time.find(i) != h_time.end())
        {
            if(min_dist[i] != INT_MAX)
            {
                min_time = min(min_time, (min_dist[i] + h_time[i]));
            }
        }
    }
    if(min_time != INT_MAX)
        cout<<min_time<<"\n";
    else
        cout<<"-1\n";

}