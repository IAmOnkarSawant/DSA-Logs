class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                count++;
            }
            else
            {
                maxLen = max(count, maxLen);
                count = 0;
            }
        }
        maxLen = max(count, maxLen);
        return maxLen;
    }
};