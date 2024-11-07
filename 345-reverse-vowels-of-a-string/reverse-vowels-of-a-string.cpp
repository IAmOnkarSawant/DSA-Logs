class Solution {
public:
    bool is_vowel(char c)
    {
        if((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') || 
           (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') )
            return 1;
        return 0;
    }
    string reverseVowels(string s) {
        int i = 0, j = s.size()-1;
        while(i < j)
        {
            bool flagi = 0, flagj = 0;
            if(!(is_vowel(s[i])))
            {
                i++;
                continue;
            }
            if(!(is_vowel(s[j])))
            {
                j--;
                continue;
            }
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};