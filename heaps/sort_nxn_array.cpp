//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    struct data{
        int val;
        int ap;
        int vp;
    };

    struct mycomp
    {
        bool operator()(struct data d1, struct data d2)
        {
            return d1.val > d2.val;
        }
    };
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {

            priority_queue< struct data ,vector<struct data>, mycomp >pq1;

            for(int i=0;i<K;i++)
            {
                data d;
                d.val=arr[i][0];
                d.ap=i;
                d.vp=0;
                pq1.push(d);
            }

            vector<int>ans;
            while(!pq1.empty())
            {
                ans.push_back(pq1.top().val);
                data temp=pq1.top();
                pq1.pop();
                int pos=temp.vp;
                pos+=1;

                if( pos < K)
                { 
                    temp.vp=pos;
                    temp.val=arr[temp.ap][temp.vp];
                    pq1.push(temp);
                }
            }

            return ans;



        // priority_queue<int,vector<int>,greater<int>>pq;


        // for(auto it:arr)
        // for(auto i:it)
        // pq.push(i);

        // vector<int>ans;
        // while(!pq.empty())
        // {
        //     ans.push_back(pq.top());
        //     pq.pop();
        // }
        // return ans;
     
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends