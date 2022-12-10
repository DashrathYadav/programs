//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        string ans;
        stack<char>st;
        int n=s.size();
        
        for(int j=0;j<n;j++){
         
            if(s[j]!=']')
            {
                st.push(s[j]);
            }
            else{
                string str="";
                while( !st.empty() &&st.top()!='[')
                {
                    str=str+st.top();
                    st.pop();
                }
                st.pop();
                reverse(str.begin(),str.end());
                string num="";
                while((!st.empty() && isdigit(st.top())) ){
                    num=num+st.top();
                    st.pop();
                }
                reverse(num.begin(),num.end());
                int N=stoi(num);
                string formed="";
                while(N--){
                    formed=formed+str;
                }

            //ans=formed;
              //  cout<<ans<<endl;
                int k=formed.size();
                for(int i=0;i<k;i++){
                    st.push(formed[i]);
                }
              //  cout<<st.size()<<endl;

            }
            

        }

        while(!st.empty()){
            ans=ans+st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends