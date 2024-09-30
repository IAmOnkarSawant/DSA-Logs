/*
3306. Count of Substrings Containing Every Vowel and K Consonants II

You are given a string word and a non-negative integer k.
Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

Example 1:

Input: word = "aeioqq", k = 1
Output: 0
Explanation:
There is no substring with every vowel.

Example 2:

Input: word = "aeiou", k = 0
Output: 1
Explanation:
The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

Example 3:

Input: word = "ieaouqqieaouqq", k = 1
Output: 3
Explanation:
The substrings with every vowel and one consonant are:
word[0..5], which is "ieaouq".
word[6..11], which is "qieaou".
word[7..12], which is "ieaouq".
 

Constraints:

5 <= word.length <= 2 * 105
word consists only of lowercase English letters.
0 <= k <= word.length - 5
*/

class Solution {
public:
    long long all_substring(string word, int k)
    {
        long long count = 0;
        int conso = 0;
        unordered_map<char, int>um;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int l = 0, r = 0;
        int n = word.size();
        while(l < n)
        {
            // cout<<l<<" "<<r<<" - "<<conso<<" "<<um.size()<<"\n";
            if(conso >= k && um.size()==5)
            {
                count += 1ll*n - r + 1;
                if(st.find(word[l]) == st.end())
                    conso--;
                else
                {
                    um[word[l]]--;
                    if( um[word[l]] == 0 )
                        um.erase(word[l]);
                }
                l++;
            }
            else
            {
                if(r == n)
                    break;
                if(st.find(word[r]) == st.end())
                    conso++;
                else
                {
                    um[word[r]]++;
                }
                r++;
            }
        }
        return count;
    }
    long long countOfSubstrings(string word, int k) {
        return all_substring(word, k) - all_substring(word, k+1);
    }
};