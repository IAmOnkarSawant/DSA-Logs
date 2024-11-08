class Solution {
public:
    bool findRec(vector<int>&matchsticks, int a, int b, int c, int d, int i)
    {
        if(i == matchsticks.size())
            return !a && !b && !c && !d;
        int curr = matchsticks[i]; 
        if(a >= curr)
        {
            if(findRec(matchsticks, a - curr, b, c, d, i+1))
                return 1;
        }
        if(b >= curr)
        {
            if(findRec(matchsticks, a, b - curr, c, d, i+1))
                return 1;
        }
        if(c >= curr)
        {
            if(findRec(matchsticks, a, b, c - curr, d, i+1))
                return 1;
        }
        if(d >= curr)
        {
            if(findRec(matchsticks, a, b, c, d - curr, i+1))
                return 1;
        }
        return 0;
    }
    bool makesquare(vector<int>& matchsticks) 
    {
        int peri = 0;
        for(auto it: matchsticks)
        {
            peri += it;
        }
        if(peri%4 != 0)
            return 0;
        int side_len = peri/4;
        sort(matchsticks.rbegin(), matchsticks.rend());
        int a = side_len, b = side_len, c = side_len, d = side_len;   
        return findRec(matchsticks, a, b, c, d, 0);
    }
};