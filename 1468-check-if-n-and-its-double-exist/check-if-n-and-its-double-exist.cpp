class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int>s;
        int n = arr.size();
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            s[arr[i]] = i;
            if(arr[i] == 0)
                cnt++;
        }
        if(cnt >= 2)
            return 1;
        for(int i = 0; i < n; i++)
        {
            int to_find = arr[i]*2;
            if(s.find(to_find) != s.end() && s[to_find] != i)
            {

                return 1;
            }
            s[(arr[i])] = i;
        }
        return 0;
    }
};