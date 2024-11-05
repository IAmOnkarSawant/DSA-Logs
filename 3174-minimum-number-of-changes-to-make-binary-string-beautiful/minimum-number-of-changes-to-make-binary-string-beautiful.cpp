class Solution {
public:
    int minChanges(string s) 
    {
        int n = s.size();
        int i = 0, j = 0;
        int cnt = 0;
        while(i < n)
        {
            j = i;
            while(j < n && s[i] == s[j])
            {
                j++;
            }
            int len = j - i;
            if(len == 1)
            {
                cnt++;
                i = j+1;
            }
            else if( len%2 )
            {
                cnt++;
                i = j+1;
            }
            else
                i = j;
        }
        return cnt;
    }
};

/*
0 1 2 3 4 5 6 7

1 1 0 0 0 1 1 
    i
          j  
*/