class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int cnt = 0;
        char prev = word[0];
        for(int i = 0; i < word.size(); i++)
        {
            if(word[i] == prev)
            {
                cnt++;
                if(cnt == 10)
                {
                    comp.push_back('9');
                    comp.push_back(word[i]);
                    cnt = 1;
                }
            }
            else
            {
                comp += to_string(cnt);
                comp.push_back(prev);
                cnt = 1;
                prev = word[i];
            }
        }
        if(cnt > 0)
        {
            comp += to_string(cnt);
            comp.push_back(prev);
        }

        return comp;
    }
};