//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:

int factorial(int n)
    {
       int  ans=1;
        for(int i=2;i<=n;i++)
            ans*=i;

            return ans;
    }

    void get_permutate(string &str,int k,string &ans)
    {
        if(k==1)
        {
            ans+=str;
            return;
        }

        int l=str.length();
        int combi_of_pre_digit=factorial(l-1);

        int place_of_digit_to_pic=k/combi_of_pre_digit;
            if( k % combi_of_pre_digit >0)
            place_of_digit_to_pic++;

            int indx_to_del=place_of_digit_to_pic-1;

            //deleting that char from string and adding to ans;
            ans+=str[indx_to_del];
            str.erase(str.begin()+indx_to_del);
            k=k-(indx_to_del *combi_of_pre_digit);

            get_permutate(str,k,ans);


    }

    string kthPermutation(int n, int k)
    {
        // code here
        
         string str="";
      for(int i=1;i<=n;i++)
        str+=to_string(i);
        string ans="";
        get_permutate(str,k,ans);
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        Solution ob;
        string ans = ob.kthPermutation(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends