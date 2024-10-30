class Solution {
public:
    vector<int> LIS(vector<int>&nums)
    {
        int n = nums.size();
        vector<int> LIS_nums(n, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if((nums[j] < nums[i]) && (LIS_nums[j]+1 > LIS_nums[i]))
                {
                    LIS_nums[i] = LIS_nums[j]+1;
                }
            }
        }
        return LIS_nums;
    }
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        vector<int>pre_LIS = LIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int>pre_LDS = LIS(nums);
        reverse(pre_LDS.begin(), pre_LDS.end());

        int ans = n-1;
        if(n < 3)
            return -1;
        for(int i = 1; i < n-1; i++)
        {
            int to_delete = 0;
            int left_size = i+1;
            int right_size = n-i;
            int del_left = left_size - pre_LIS[i];
            int del_right = right_size - pre_LDS[i];
            if(del_left != left_size-1 && del_right != right_size-1)
            {
                ans = min(ans, del_left + del_right);
            }   
        }
        if(ans == n-1)
            return -1;
        return ans;
    }
};