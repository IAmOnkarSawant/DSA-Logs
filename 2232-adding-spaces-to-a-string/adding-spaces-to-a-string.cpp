class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int offset = 0;
        int j = 0;
        string ans = "";
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(j < spaces.size() && (spaces[j]) == i)
            {
                ans.push_back(' ');
                offset++;
                j++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};

// 1 5 7 9 
//   j

// 0123456789 
// i code in python
