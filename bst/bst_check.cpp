#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
 };
 /*
//             5
//           /  \
//          /    \
//          3     7
//         / \    / \
//        2   4  6   8
*/

bool bst_check(struct node* root,struct node*min,struct node*maxx)
{
    if(root==NULL)
    return true;

    if(min!=NULL && root->data <=min->data)
    return false;

    if(maxx !=NULL && root->data >= maxx->data )
    return false;

    bool left_sub_tree=bst_check(root->left,min,root);
    bool right_sub_tree=bst_check(root->right,root,maxx);

    return left_sub_tree && right_sub_tree;
}

int main()
{
    struct node*root=new node(5);
    root->left=new node(3);
    root->right=new node(7);
    root->left->left=new node(2);
    root->left->right= new node(4);
    root->right->left= new node(6);
    root->right->right= new node(8);
    cout<<bst_check(root,NULL,NULL)<<endl;
    return 0;
}
