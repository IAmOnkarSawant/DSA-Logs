class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int>sets(33, 0);
        for(int c : candidates)
        {
            for(int i = 0; i < 32; i++)
            {
                sets[i] += ((c >> i) & 1);
            }
        }
        return *max_element(sets.begin(), sets.end());
    }
};
