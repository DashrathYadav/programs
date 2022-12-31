/*
https://practice.geeksforgeeks.org/problems/af49b143a4ead583e943ca6176fbd7ea55b121ae/1
*/

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        // Code here
        vector<pair<int,int>>time;
int n=N;
for(int i=0;i<n;i++)
{
    time.push_back({start[i],end[i]});
}

sort(time.begin(),time.end());

// // for(int i=0;i<n;i++)
// // cout<<time[i].first<<" "<<time[i].second<<endl;

// return 1;

        priority_queue<int,vector<int>,greater<int>>pq;
        int min_laptop=0;


        for(int i=0;i<N;i++)
        {
            if(pq.empty())
            {
                pq.push(time[i].second);
                min_laptop+=1;
            }
            else{

                if(time[i].first >= pq.top())
                {
                    pq.pop();
                    pq.push(time[i].second);
                }
                else{
                    pq.push(time[i].second);
                    min_laptop++;

                }

            }
        }

        return min_laptop;


    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int start[N], end[N];
        for(int i=0; i<N; i++)
            cin>>start[i];
        for(int i=0; i<N; i++)
            cin>>end[i];
            
        Solution ob;
        cout << ob.minLaptops(N, start, end) << endl;
    }
}
// } Driver Code Ends