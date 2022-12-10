#include<bits/stdc++.h>
using namespace std;

unordered_map<int,vector<int>>h;

struct node{
    int data;
    struct node* left;
    struct node* right;
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

void vertical_storing(struct node*root,int hd)
{
    //preorder traversal;
    if(root==NULL)
    return;

    h[hd].push_back(root->data);
    vertical_storing(root->left,hd-1);
    vertical_storing(root->right,hd+1);

}

int main()
{
   struct node*root=new node(10);
   root->left=new node(7);
   root->right=new node(4);
   root->left->left=new node(3);
   root->left->right=new node(11);
    root->right->left=new node(14);
       root->right->right=new node(6);
       vertical_storing(root,0);

       unordered_map<int,vector<int>>:: iterator it;
       for(it=h.begin();it!=h.end();it++)
       {
           vector<int>::iterator ij;
           vector<int >a;
           a=it->second;
           for(ij=a.begin();ij!=a.end();ij++)
           {
               cout<<*ij<<" ";
               
           }
           cout<<endl;
       }


     
}