class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<long long, int>>dq;
        long long cum_sum = 0;
        int min_len = nums.size()+1;
        for(int i = 0; i < nums.size(); i++)
        {
            cum_sum += nums[i];

            if (cum_sum >= k) {
                min_len = min(min_len, i + 1);
            }

            while((dq.empty() != 1)  &&  (dq.back().first >= cum_sum))
            {
                dq.pop_back();
            } 
           

            while((dq.empty() != 1) && (cum_sum - dq.front().first) >= k)
            {
                min_len = min(min_len, (i - dq.front().second));
                dq.pop_front();
            }
            dq.push_back({cum_sum, i});
        }
        return min_len == nums.size() + 1 ? -1 : min_len;
    }
};