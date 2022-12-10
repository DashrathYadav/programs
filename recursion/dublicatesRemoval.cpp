#include<bits/stdc++.h>
using namespace std;


string dublicateRemoval(string str,int idx,string newStr)
{
    if(idx == str.length())
    return newStr;

    static int map[26]={0};

    char ch=str[idx];

    int pidx=ch-'a';
    if(map[pidx]==0)
    {
        newStr=newStr +ch;
        map[pidx]=1;
    }
     return dublicateRemoval(str,idx+1,newStr);
     
  return str;
}

int main()
{
    string str;
    cin>>str;
    string str1;
     string newStr= dublicateRemoval(str,0,str1);
     cout<<newStr;

}