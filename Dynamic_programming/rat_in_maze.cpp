#include<bits/stdc++.h>
using namespace std;


vector<string>maze_directions(int r,int c,int n,int m)
{
    if(r== n-1 && c==m-1)
    {
        vector<string> v;
        v.push_back("");
        return v;
    }
          //  cout<<r<<" "<<c<<endl;
         vector<string> p1;
        vector<string>p2;
        if(c < n-1)
     p1= maze_directions(r,c+1,n,m);

     if(r < n-1)
     p2=maze_directions(r+1,c,n,m);

     vector<string>ans;
     for(auto it: p1)
     {
        ans.push_back('h'+it);
     }
     for(auto it: p2)
     {
        ans.push_back('v'+it);
     }

     return ans;
}

void maze_direction(int r,int c,int n,int m,string d,vector<string>&ans)
{
    if(r==n-1 && c==m-1)
    {
        ans.push_back(d);
        return;
    }

    if(r < n-1)
    maze_direction(r+1,c,n,m,d+'v',ans);

    if(c < m-1)
    maze_direction(r,c+1,n,m,d+'h',ans);
        
}

int main()
{

    int n,m;
    cin>>n>>m;



    vector<string> ans;
     maze_direction(0,0,n,m,"",ans);

        for(auto it:ans){
        cout<<it<<endl;
        }



 return 0;
}