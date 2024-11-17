// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
        
//     }
// };

class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        int min_len = n+1;
        long long sum = 0;
        while(right < n)
        {
            sum += nums[right];
            while(left <= right && sum >= k)
            {
                min_len = min(min_len, (right - left + 1));
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if(min_len == n+1)
            return 0;
        return min_len;
    }
};