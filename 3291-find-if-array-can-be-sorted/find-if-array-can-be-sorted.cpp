class Solution {
public:
    int count_set_bits(int num)
    {
        int cnt = 0;
        while(num > 0)
        {
            cnt++;
            num = num & num-1;
        }
        return cnt;
    }
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> set_bits;
        for(int num: nums)
        {
            set_bits.push_back(count_set_bits(num));
            // cout<<set_bits.back()<<" ";
        }

        for(int i = 0; i < n-1; i++)
        {
            for(int j = 0; j < n-i-1; j++)
            {
                if(nums[j+1] < nums[j])
                {
                    if(set_bits[j] == set_bits[j+1])
                    {
                        swap(nums[j], nums[j+1]);
                        swap(set_bits[j], set_bits[j+1]);
                    }
                    else
                    {
                        return 0;
                    }
                }
            }
        }
        // cout<<"\n";
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<nums[i]<<" ";
        // }
        return 1;
    }
};