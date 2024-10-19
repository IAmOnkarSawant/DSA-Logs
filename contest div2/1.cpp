#include <bits/stdc++.h>
using namespace std;

int solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int sum = (n-1)*((*max_element(a.begin(), a.end())) - (*min_element(a.begin(), a.end())));
    return sum;
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