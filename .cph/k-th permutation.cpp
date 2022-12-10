#include<bits/stdc++.h>
using namespace std;
void permutate(string &str,vector<string>&ans,string &s,vector<int>&v)
{
       
    for(int i=0;i<str.size();i++)
    {
        if(v[i]==0){
            v[i]=1;
            s.push_back(str[i]);
             if(s.size()==str.size())
             { ans.push_back(s);}
            permutate(str,ans,s,v);
            v[i]=0;
            s.pop_back();
        }
    }
}



int main(){
    string str="abc";
    int n=str.size();
    vector<int>v(n,0);
    vector<string>ans;
    string s;
    permutate(str,ans,s,v);

    // for(int i=0;i<ans.size();i++){
    //         cout<<ans[i]<<" ";
    //     }
        cout<<ans[0];
 }

