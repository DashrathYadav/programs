#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>children;

};

 Node* generic_tree_construction(vector<int>arr)
 {
    
    stack<Node*>stk;
    Node *root;
    for(auto it : arr)
    {

       
       if(it==-1)
       {
        stk.pop();
       }
       else{
            Node* newnode =new Node;
            newnode->data=it;

            if(!stk.empty())
            {
                stk.top()->children.push_back(newnode);
            }
            else
            {
                root=newnode;
            }

            stk.push(newnode);

       }
    }

    return root;
 }


void generic_tree_display(Node* root)
{
    cout<<root->data<<"  -> ";
    for(auto it : root->children)
    {
        cout<<it->data<<" , ";
    }
    cout<<endl;

    for(auto it : root->children)
    generic_tree_display(it);
}

int tree_size(Node* root)
{
    int cnt=0;
    for(auto it : root->children)
    {
        cnt+=tree_size(it);
    }
    return cnt+1;
}

int maximum_element(Node *root)
{
    int maxi=root->data;
    for(auto it : root->children)
    {
        maxi=max(maxi,maximum_element(it));
    }

    return maxi;
}

int main()
{
   
    vector<int>v={10,20,50,-1,60,-1,-1,30,10,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    
   // vector<int>v={10,11,-1,12,-1,-1};
   Node* root= generic_tree_construction(v);
// generic_tree_display(root);
// cout<<tree_size(root);
   cout<<maximum_element(root);

}