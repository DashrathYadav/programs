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

int tree_height( Node* root)
{
        int h=-1;
        for(auto it :root->children)
        {
             h=max(h,tree_height(it));
        }
        return h+1;
}


void tree_level_order_traversal(Node * root)
{
    queue<Node*>pq;
    queue<Node *>cq;
    pq.push(root);

    
    while(!pq.empty())
    {

        while(!pq.empty()){
        Node* temp=pq.front();
        pq.pop();
        
       cout<< temp->data<< "  ";
        int s=temp->children.size();
        for(int i=0;i<s;i++)
        {
            cq.push(temp->children[i]);
        }
        }
        cout<<"\n";
        while(!cq.empty())
        {
            pq.push(cq.front());
            cq.pop();
        }
    }
}


void tree_zig_zag_traversal(Node* root)
{
    queue<Node*>q;
    stack<Node*>s;
    bool dir=0;
    q.push(root);
 
    while(!q.empty())
    {
        while(!q.empty())
    {
        Node*temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(dir==1)
        {
            for(int i=temp->children.size()-1;i>=0;i--)
            {
                s.push( temp->children[i] ) ;
            }
        }
        else{

            for(int i=0;i<temp->children.size();i++)
            {
                s.push( temp->children[i]);
            }
        }

    }
    while(!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    cout<<"\n";
    dir=!dir;
}

}

bool isLeaf(Node*root)
{
        if(root->children.size()==0)
        return 1;
        else return 0;
}





void leaf_node_removal(Node*root)
{
    for(int i=root->children.size()-1;i>=0;i--)
    {
        if(isLeaf(root->children[i]))
        root->children.erase(root->children.begin()+i);
    }
    for(auto it:root->children)
    {
        leaf_node_removal(it);
    }
}


void linearize_tree(Node* root,vector<Node*>arr)
{
    for(auto it:arr)
    {
        root->children.push_back(it);
    }
    vector<Node*>send_arr;
    while(root->children.size() >1)
    {
        send_arr.push_back(root->children[1]);
        root->children.erase(root->children.begin()+1);
    }
    if(send_arr.size()>=1)
    linearize_tree(root->children[0],send_arr);
}


Node* tailNode(Node * root)
{
        while(root->children.size()>=1)
        {
            root=root->children[0];
        }
        return root;
}
void linerize_tree1(Node*root)
{
    for(auto it: root->children)
    {
        linerize_tree1(it);
    }

    while( root->children.size() >1)
    {
        Node*last=root->children[root->children.size()-1];
        root->children.erase(root->children.begin()+root->children.size()-1);
        Node*second_last=root->children[root->children.size()-1];
        Node*tsl=tailNode(second_last);
        tsl->children.push_back(last);

    }

}

 bool tree_search(Node * root,int data)
 {
        if(root->data ==data)
    return true;

    for( auto it : root->children)
    {
        if( tree_search(it,data))
        return true;

    }
    return false;   
 }


 bool find_path(Node *root,int data,vector<int>&v)
 {
        if(root->data==data)
        {
            v.push_back(data);
            return true;
        }
        for(int i=0;i<root->children.size();i++)
        {
                if( find_path(root->children[i],data,v) )
                {
                    v.push_back(root->data);
                    return true;
                }
        }

        return false;

 }

 void lowest_comman_Ancestor(Node* root,int data1,int data2)
 {
    vector<int>p1;
    vector<int>p2;
        find_path(root,data1,p1);
        find_path(root,data2,p2);

//   for(int i=0;i<p1.size();i++)
//     cout<<p1[i]<<" ";
//     cout<<endl;
//   for(int i=0;i<p2.size();i++)
//     cout<<p2[i]<<" ";

        int m=min(p1.size(),p2.size());
        for(int i=m-1;i>=0;i--)
        {
            if(p1[i]!=p2[i])
            {
                i+=1;    // when not comman then is previou was comman that was ancestor;
        cout<<" ancestor is  "<<p1[i]<<endl;
        break;
            }
        }

 }

int main()
{
   
    vector<int>v={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    
//    vector<int>v={10,11,-1,12,-1,-1};
   Node* root= generic_tree_construction(v);
// generic_tree_display(root);
// cout<<tree_size(root);
//    cout<<maximum_element(root);
// cout<<tree_height(root);
//  tree_level_order_traversal(root);
// tree_zig_zag_traversal(root);
// leaf_node_removal(root);
// cout<<"\n\n";
// vector<Node*>e;
// linearize_tree(root,e);
// linerize_tree1(root);
//   linerize_tree1(root);
// tree_level_order_traversal(root);
// cout<<tree_search(root,40)<<endl;
// vector<int>path;
// if(find_path(root,100,path))
// {
//     for(int i=0;i<path.size();i++)
//     cout<<path[i]<<" ";
// }
// else{
//     cout<<" No path Exist"<<endl;
// }

lowest_comman_Ancestor(root,80,90);

}