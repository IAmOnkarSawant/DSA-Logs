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


void inorder(node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

int main()
{
    node* root = NULL; 
    srand((unsigned) time(0));  
    for(int i = 0; i < 15; i++)
    {
        int num = rand() % 100;
        root = insert(root, num);
        cout << "MIN: " << min_val(root) << endl;
        cout << "MAX: " << max_val(root) << endl;

    }
    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << endl;
    return 0;
}