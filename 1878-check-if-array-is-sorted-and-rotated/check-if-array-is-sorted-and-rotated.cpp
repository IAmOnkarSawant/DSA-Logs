class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int interest = -1;
        int n = nums.size();

        for(int i = 0; i < n-1; i++)
        {
            if(nums[i+1] < nums[i]){
                interest = i+1;
                break;
            }
        }

        if(interest == -1)
            return 1;
        
        for(int i = 1; i < n; i++)
        {
            if(nums[(interest+i-1)%n] > nums[(interest+i)%n])
            {
                return 0;
            }
        }
        return 1;
    }
};

