//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:

    Node* construct_tree(int in[],int pre[],map<int,int>&index,int pre_start,int pre_end,int in_start,int in_end)
    {
            if(pre_start > pre_end || in_start > in_end)
            {
                return NULL;
            }


        Node * newnode= new Node(pre[pre_start]);

        
        int in_index=index[pre[pre_start]];
        int size=in_index-in_start;
            newnode->left=construct_tree(in,pre,index,pre_start+1,pre_start+size,in_start,in_index-1);
            newnode->right=construct_tree(in,pre,index,pre_start+size+1,pre_end,in_index+1,in_end);

            return newnode;



    }

    Node* buildTree(int in[],int pre[], int n)
    {

        map<int,int>index;
        for(int i=0 ; i < n ; i++)
        {
                index[in[i]]=i;
        }
        int pre_start=0;
        int pre_end=n-1;
        int post_start=0;
        int post_end=n-1;

            Node* head= construct_tree(in,pre,index,pre_start,pre_end,post_start,post_end);

    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends