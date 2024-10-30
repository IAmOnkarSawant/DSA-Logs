#include <bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* left;
    node* right;

    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};

node* insert(node* root, int val)
{
    if( root == NULL)
    {
        return new node(val);
    }   
    if(root->val > val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

int min_val(node* root)
{
    if(root == NULL) return -1;
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root->val;
}

int max_val(node* root)
{
    if(root == NULL) return -1;
    while(root->right != NULL)
    {
        root = root->right;
    }
    return root->val;
}


void all_traversal(node* root, vector<vector<int>>& ans)
{
    if(root == NULL)
        return;

    ans[0].push_back(root->val);
    all_traversal(root->left, ans);
    ans[1].push_back(root->val);
    all_traversal(root->right, ans);
    ans[2].push_back(root->val);
}

void all_traversal_it(node* root, vector<vector<int>>& ans)
{
    stack<pair<node*, int>> st;
    st.push({root, 0});
    while(st.empty() == false)
    {
        auto it = st.top();
        st.pop();
        if(it.second == 0)
        {
            ans[0].push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left)
            {
                st.push({it.first->left, 0});
            }
        }
        else if(it.second == 1)
        {
            ans[1].push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right)
            {
                st.push({it.first->right, 0});
            }
        }
        else
        {   
            ans[2].push_back(it.first->val);
        }
    }
}

int main()
{
    node* root = NULL; 
    srand((unsigned) time(0));  
    for(int i = 0; i < 7; i++)
    {
        int num = rand() % 100;
        root = insert(root, i+1);
    }
    vector<vector<int>> ans(3, vector<int>());
    cout << "ALL Traversal: \n";
    all_traversal(root, ans);
    for(auto vec: ans)
    {
        for(auto num: vec)
        {
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    vector<vector<int>> ans1(3, vector<int>());
    cout << "ALL Traversal: \n";
    all_traversal_it(root, ans1);
    for(auto vec: ans1)
    {
        for(auto num: vec)
        {
            cout<<num<<" ";
        }
        cout<<"\n";
    }
    cout << endl;
    return 0;
}