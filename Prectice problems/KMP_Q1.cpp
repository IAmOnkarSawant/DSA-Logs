// leetcode shortest palindrome.

class Solution {
public:
    void lps_helper(string& s, vector<int>& lps)
    {
        int n = s.size();
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while(i < n)
        {
            if(s[len] == s[i])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len > 0)
                    len = lps[len-1];
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
    }
    string shortestPalindrome(string s) 
    {
        int n = s.size();
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        string combined = s + "#" + rev;

        vector<int>lps(combined.size(), 0);
        lps_helper(combined, lps);
        int max_val = lps[combined.size()-1];
 
        string ans = rev.substr(0, (rev.size()-max_val));
        return ans+s;
    }
};