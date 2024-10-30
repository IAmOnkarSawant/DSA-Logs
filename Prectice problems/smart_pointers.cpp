#include <bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node(int n, int m)
    {
        if(n > m)
            val = n;
        else 
            val = -1;
    }
};

int main()
{
    unique_ptr<node> ptr1 = make_unique<node>(100,20);
    cout<<ptr1->val<<"\n";

}