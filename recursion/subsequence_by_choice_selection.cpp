#include<bits/stdc++.h>
using namespace std;

 void subsequences(string str,string ans)
 {
    if(str.size()==0)
    {
        cout<<ans<<endl;
        return;
    }


        char ch=str[0];
      
        subsequences(str.substr(1,str.size()-1),ans+ch);
      
        subsequences(str.substr(1,str.size()-1),ans);

 }

int main()
{
    string str="123";
    // cin>>str;
    cout<<str<<endl;

    subsequences(str,"");



 return 0;
}