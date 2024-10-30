// leetcode find needle in haystack

class Solution {
public:
    void lps_helper(string& needle, vector<int>& lps)
    {
        int n = needle.size();
        lps[0] = 0;
        int i = 1;
        int len = 0;
        while(i < n)
        {
            if(needle[i] == needle[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if(len > 0)
                {
                    len = lps[len-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    int strStr(string haystack, string needle) {
        int m = needle.size();
        int n = haystack.size();

        vector<int>lps(m);
        lps_helper(needle, lps);
        
        int i = 0, j = 0;
        while( i < n )
        {
            if(haystack[i] == needle[j])
            {
                i++; j++;
                if(j == m)
                    return i - j;
            }
            else
            {
                if(j > 0)
                    j = lps[j-1];
                else
                {
                    j = 0;
                    i++;
                }
            }
        }

        return -1;
    }
};