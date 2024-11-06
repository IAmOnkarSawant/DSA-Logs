class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int dupFree = -1;
        int i = 0;
        while(i<n)
        {
            dupFree++;
            nums[dupFree] = nums[i];

            while(i < n && nums[dupFree]==nums[i])
                i++; 
        }
        return dupFree+1;
    }
};