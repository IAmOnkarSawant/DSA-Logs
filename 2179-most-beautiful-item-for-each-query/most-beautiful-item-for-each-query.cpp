class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = items.size();
        sort(items.begin(), items.end());
        vector<int> max_price(n, 0);
        max_price[0] = items[0][1];
        for (int i = 1; i < n; i++) 
        {
            max_price[i] = max(max_price[i - 1], items[i][1]);
        }

        vector<int> ans;

        for (int query : queries) 
        {
            if (query < items[0][0]) 
            {
                ans.push_back(0);
            } 
            else if (query >= items[n - 1][0]) 
            {
                ans.push_back(max_price[n - 1]);
            } 
            else 
            {
                int low = 0, high = n - 1;
                while (low < high) {
                    int mid = (low + high + 1) / 2;
                    if (items[mid][0] <= query) 
                    {
                        low = mid;
                    } 
                    else
                    {
                        high = mid - 1;
                    }
                }
                ans.push_back(max_price[low]);
            }
        }

        return ans;
    }
};
