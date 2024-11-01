class Solution {
public:
    string makeFancyString(string s) 
    {

        string ans = "";
        int n = s.size();
        if(n < 3)
            return s;
        char a = s[0];
        char b = s[1];
        char c = s[2];
        for(int i = 2; i < n; i++)
        {
            c = s[i];
            if(!(a == b && b == c))
            {
                ans.push_back(a);
            }
            a = b;
            b = c;
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};