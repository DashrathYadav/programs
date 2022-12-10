#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node* left;
    struct node* right;
    
};
 struct node* createnode(int data)
 {
     struct node* Node=new node;
     Node->data=data;
     Node->left=NULL;
     Node->right=NULL;
    return Node;
 }

 struct node* insertnode(struct node*root,int data)
 {
     if(root==NULL)
     {
         root=createnode(data);
         return root;
     }
     queue<struct node*>q;
     q.push(root);
     while(!q.empty())
     {
         struct node*temp=q.front();
         q.pop();

         if(temp->left !=NULL)
         q.push(temp->left);
         else{
             temp->left=createnode(data);
             return root;
         }

         if(temp->right != NULL)
         q.push(temp->right);
         else{
             temp->right=createnode(data);
             return root;
         }

     }
 }

  void level_order_traversal(struct node*root)
  {
      if(root==NULL)
      return ;
 queue<struct node*>q;
     q.push(root);
     while(!q.empty())
     {
         struct node*temp=q.front();
         cout<<temp->data<<" ";
         q.pop();

         if(temp->left !=NULL)
         q.push(temp->left);
        
         if(temp->right != NULL)
         q.push(temp->right);
         
  }
  }
    

int main()
{
    struct node*root=createnode(1);
    root->left=createnode(2);
    root->right=createnode(3);
    root->left->right=createnode(5);

    level_order_traversal(root);
    insertnode(root,4);
    level_order_traversal(root);

}