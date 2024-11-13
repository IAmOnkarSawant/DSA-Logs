class Solution {
public:
    int find_ind(vector<int>& nums,int i, int j, int num)
    {
        int n = nums.size();
        int low = i, high = j;
        int ans = -1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(nums[mid] < num)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long count = 0;
        for(int i = 1; i < n; i++)
        {
            int low = find_ind(nums, 0, i-1, lower - nums[i])+1;
            int high = find_ind(nums, 0, i-1, upper+1-nums[i])+1;
            cout<<low<<" "<<high<<"\n";
            count += high - low ;
        }
        return count;
    }
};

