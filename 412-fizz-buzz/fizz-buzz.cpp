class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string>final_ans;
        for(int i = 1; i <= n; i++)
        {
            string ans = "";
            if(i % 3 == 0)
                ans += "Fizz";
            if(i % 5 == 0)
                ans += "Buzz";
            if(ans.empty())
                ans += to_string(i);
            final_ans.push_back(ans);
        }
        return final_ans;
    }
};