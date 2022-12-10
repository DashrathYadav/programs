//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends
struct node{
    int val;
    int ap;
    int vp;
};


struct mycomp{
    bool operator()(struct node n1, struct node n2)
    {
        return n1.val > n2.val;      

    }
};

int kthSmallest(int mat[MAX][MAX], int n, int k)
{
    priority_queue< node, vector<node>, mycomp> pq;
    priority_queue< int > pq1;

    int cnt=0;
    struct node n1;
    for(int i=0;i<n;i++)
    {
        n1.val=mat[i][0];
        n1.ap=i;
        n1.vp=0;
        pq.push(n1);
    }
int cnt=n;
    while(!pq.empty())
    {
        
        node temp=pq.top();
        pq.pop();

        if( (temp.vp)+1 >=n)
        continue;

        temp.vp+=1;
        temp.val=mat[temp.ap][temp.vp];
        pq.push(temp);

        pq1.push(pq.top().val);
        
        if(pq1.size() == k)
        break;

    }
    
    return pq1.top();
}
