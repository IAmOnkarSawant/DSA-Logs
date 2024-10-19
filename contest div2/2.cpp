#include <bits/stdc++.h>
using namespace std;

string solve()
{
    int n; 
    cin>>n;
    string s(n-1, '0');
    return s+"1";
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