class Solution {
public:
    int fact(int i)
    {
        if( i== 1)
            return 1;
        return i * fact(i-1);
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) 
    {
        int n = nums.size();
        set<vector<int>>ans;
        int total = fact(n);
        for(int i = 0; i < total; i++)
        {
            next_permutation(nums.begin(), nums.end());
            ans.insert(nums);
        }    
        vector<vector<int>>ret;
        for(auto it: ans)
            ret.push_back(it);
        return ret;
    }
};