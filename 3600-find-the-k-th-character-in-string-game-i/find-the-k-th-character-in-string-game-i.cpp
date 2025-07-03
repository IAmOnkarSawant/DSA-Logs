class Solution {
public:
    char kthCharacter(int k) {
        string ans = "a";
        for(int i = 1; i <= 9; i++ )
        {
            int n = ans.size();
            for(int j = 0; j < n; j++)
            {
                char curr_char = ans[j];
                if(curr_char == 'z')
                    curr_char = 'a';
                else 
                    curr_char++;
                ans.push_back(curr_char);
            }
            if(ans.size() >= k)
                break;
        }
        return ans[(k-1)];
    }
};