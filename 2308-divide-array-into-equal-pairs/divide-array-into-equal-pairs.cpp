class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int a[501] = {0};
        int n = nums.size();
        for(int num: nums)
        {
            a[num]++;
        }

        for(int i = 0; i < 501; i++)
        {
            if(a[i]%2 != 0)
            {
                return false;
            }
        }
        return true;
    }
};