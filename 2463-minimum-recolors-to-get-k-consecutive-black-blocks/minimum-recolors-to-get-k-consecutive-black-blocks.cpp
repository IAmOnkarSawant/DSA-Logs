class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int W = 0; int B = 0;
        int n = blocks.size();
        for(int i = 0; i < k; i++)
        {
            if(blocks[i] == 'W')
                W++;
            else
                B++;
        }

        int ans = INT_MAX;
        ans = min(W, ans);

        for(int i = k; i < n; i++)
        {
            if(blocks[i] == 'W')
                W++;
            else
                B++;

            if(blocks[i-k] == 'W')
                W--;
            else
                B--;

            ans = min(W, ans);
        }
        return ans;
    }   
};