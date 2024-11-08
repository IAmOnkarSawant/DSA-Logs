class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>ans;
        int pre_xor = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            pre_xor ^= nums[i];
            int  k = 0;
            for(int i = 0; i < maximumBit; i++)
            {
                if(((pre_xor>>i) & 1) == 0)
                {
                    k = k | (1 << i);
                }
            }
            ans.push_back(k);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};