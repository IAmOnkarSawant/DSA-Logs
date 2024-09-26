// leetcode: longest happy prefix

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
    string longestPrefix(string s) {
        vector<int>lps(s.size());
        lps_helper(s, lps);
        return s.substr(0,lps[s.size()-1]);
    }
};