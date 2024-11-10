class Solution {
public:
    string bits_count(int n)
    {
        string s = "";
        int cnt = 0;
        while(n > 0)
        {
            if(n & 1)
                s+="1";
            else
                s+= "0";
            n = n >> 1;
        }
        return s;
    }
    long long ans_find(string s)
    {
        // cout<<s<<" ";
        reverse(s.begin(), s.end());
        long long ans = 0;
        for(char ch: s)
        {
            ans = (ans << 1) | (ch == '1' ? 1 : 0);
        }
        return ans;
    }
    long long minEnd(int n, int x) 
    {   
        if(n == 1)
            return x;
        string n_s = bits_count(n-1);
        string x_s = bits_count(x);
        cout<<n_s<<" "<<x_s<<"\n";
        int j = 0;
        int ns = x_s.size();
        for(int i = 0; i < n_s.size(); i++)
        {
            if(j < ns)
            {
                while(j < ns && x_s[j] == '1')
                {
                    j++;
                }
                if( j < ns)
                {
                    x_s[j] = n_s[i];
                    j++;
                }
                else
                {
                    // cout<<n_s[i]<<"- inhere\n";
                    x_s.push_back(n_s[i]);
                    // cout<<x_s<<"\n";
                }
                
            }
            else
            {
                // cout<<i<<"- here";
                x_s.push_back(n_s[i]);
            }
        }

        return ans_find(x_s);
    }
};
