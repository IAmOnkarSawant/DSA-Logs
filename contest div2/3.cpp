#include <bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    cin>>n;
    
    string s;
    cin>>s;
    bool ans = 0;

    int last = s[n-1] - '0';
    int first = s[0] - '0';

    if(last == 1 || first == 1)
        return "YES";
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cout<<solve()<<"\n";
    }
    return 0;
}