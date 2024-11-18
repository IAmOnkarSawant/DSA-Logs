class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        vector<int>ans;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            if(k >= 0)
            {
                for(int j = i+1; j <= i+k; j++)
                {
                    sum += code[j%n];
                }
            }
            else
            {
                for(int j = i-1; j >= i+k; j--)
                {
                    sum += code[(j+n)%n];
                }
            }
            
            ans.push_back(sum);
        }
        return ans;
    }
};