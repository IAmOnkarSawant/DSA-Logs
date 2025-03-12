class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int n = 1000005;
        vector<int> ans;
        vector<bool> is_prime(n+1, true);
        is_prime[0] = is_prime[1] = false;
        for (int i = 2; i <= sqrt(n); i++) {
            if (is_prime[i]) {
                for (int j = i * i; j <= n; j += i)
                    is_prime[j] = false;
            }
        }
        for(int i=2;i<is_prime.size();i++){
            if(is_prime[i]){
                ans.push_back(i);
            }
        }

        int mini_diff = INT_MAX;
        int left_num = -1, right_num = -1;
        int prev = -1;
        for(int i = 0; i < ans.size(); i++)
        {
            if(prev == -1)
            {
                if(ans[i] >= left)
                    prev = ans[i];
            }
            else if(ans[i] <= right)
            {
                // cout<<ans[i]<<" ";
                int curr_diff = (ans[i] - prev);
                if(mini_diff > curr_diff)
                {
                    mini_diff = curr_diff;
                    left_num = prev;
                    right_num = ans[i];
                }
                prev = ans[i];
            }
        }
        if(left_num == -1 || right_num == -1)
            return {-1, -1};
        
        return {left_num, right_num};
    }
};