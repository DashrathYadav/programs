#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node*right;
    node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;

    }
};

 struct node* sorted_array_to_bst(int a[],int start,int end)
 {
      if(start > end)
     return NULL;

     if(start==end)
     {
         struct node*root=new node(a[start]);
          return root;
         
     }
   

     int mid=(start+end)/2;
     struct node* root = new node(a[mid]);
     root->left=sorted_array_to_bst(a,start,mid-1);
     root->right=sorted_array_to_bst(a,mid+1,end);
   
 }
 void preorser_traversal(struct node*root)
 {
     if(root==NULL)
     return ;

     cout<<root->data<<' ';
     preorser_traversal(root->left);
     preorser_traversal(root->right);
 }





int main()
{
    int a[]={1,2,3,4,5};
    struct node*root=sorted_array_to_bst(a,0,4);
    preorser_traversal(root);


}