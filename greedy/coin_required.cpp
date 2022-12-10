#include<bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin>>t;
    int flag=0;
    for(int T=0;T<t ;T++)
    {
        priority_queue<int,vector<int>>heap;
        int n;
        cin>>n;
        vector<pair<int,int >>arr;
        int d,f;
        for(int i=0;i<n;i++)
        {
            cin>>d>>f;
            pair<int,int> p;
            p.first=d;
            p.second=f;
            arr.push_back(p);
        }
        int dist,fuel;
        cin>>dist>>fuel;
        
        for(int i=0;i<n;i++)
        {
            arr[i].first=dist-arr[i].first;
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
        {
            cout<<arr[i].first<<" "<<arr[i].second<<endl;
        }
        int cnt=0;
        int dist_cov=0;
        int idx=0;
        for(int i=0;i<n;i++)
        {

            dist=dist-fuel;
            if(dist <=0)
            {
                cout<<cnt<<endl;
                flag=1;
                break;
                
            }
            
            dist_cov=dist_cov+fuel;

            while(arr[idx].first <= dist_cov  && idx < n)
            {
                heap.push(arr[idx].second);
                idx++;
            }
            if(heap.empty())
            break;

            if(!heap.empty())
           { fuel=heap.top();
           cnt++;
            heap.pop();
           }

        }

        if(flag=0)
        cout<<-1<<endl;


    }
}
