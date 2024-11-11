class Solution {
public:
    vector<int> sieve(int n)
    {
        vector<int> S(n, 1);
        vector<int> primes;
        S[0] = 0;
        S[1] = 0;
        for(int i = 2; i*i < n; i++)
        {
            for(int j = i*i; j < n; j+=i)
            {
                S[j] = 0;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(S[i] == 1)
            {
                primes.push_back(i);
            } 
        }
        return primes;
    }

    bool primeSubOperation(vector<int>& nums) 
    {
        vector<int>primes = sieve(2005);
        int n = nums.size();
        for(int i = n-2; i>=0; i--)
        {
            if(nums[i] >= nums[i+1])
            {
                int desired = nums[i] - (nums[i+1]-1);
                int prime = *lower_bound(primes.begin(), primes.end(), desired);
                cout<<desired<<"- "<<prime<<" ";
                nums[i] -= prime;
            }
            if(nums[i+1] > nums[i] && nums[i] <= 0)
                return 0;
        }    
        return 1;
    }
};