#include<bits/stdc++.h>
using namespace std;

void generate_sequence_using_single_letter(char s,vector<string>&ans)
{
        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            ans.push_back(ans[i]+s);
        }

}

void subsequences(string str,vector<string>&ans)
{
    if(str.size() ==1)
    { 
        ans.push_back(str);
        return;
    }
    

    string newstr=str.substr(0,str.size()-1);
     subsequences(newstr,ans);
    generate_sequence_using_single_letter(str[str.size()-1],ans);    
    
}

int main()
{

    string str="123";
   vector<string>ans;
   ans.push_back("");
 subsequences(str,ans);
 for(int i=0;i<ans.size();i++)
 cout<<ans[i]<<" ";
 return 0;
}