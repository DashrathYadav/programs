
/*



just look upon  previous ones if  any one is less then you and its count is greater or
equal to you   add it count +1 to your self  because u are bigger 

but it usese O(N X N) aproach
 we have better aproach in O(nlong n); 


//printing longest increasing sequence

using this u can print the maximum increasing sequence 
in dp array start from maximum stored count print value from value array of 
correspoding indx  and traverse back for finding count max-1  till cnt=1;  

*/


#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;

    int N=n;
    vector<int>H(n);

    for(int i=0;i<n;i++)
        cin>>H[i];


  vector<int>dp(N+1,1);
        
        
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<i;j++)
            {
                if( H[i] > H[j])
                {
                    if( dp[j] >= dp[i])
                    dp[i]=dp[j]+1;
                }
            }
        }
       
        
        int maxi=1;
        for(int i=0;i<N;i++)
        maxi=max(dp[i],maxi);


        cout<<"Longest increasing sequence count is"<<maxi<<endl;

 return 0;
}

/*
Optimised veresion of LIS just to find the Longest increasing sequence size;


  vector<int>ans;                       // creating arrray
      ans.push_back(H[0]);              // pusing first element of value array
      
      for(int i=1;i<N;i++)              // iterating for remaining element in array
      {
          
          
          // --finding such element in ans which is just grater or equal to current element 
          int indx=lower_bound(ans.begin(),ans.end(),H[i])-ans.begin();  
          
          
          // if not exist push currrent element in ans it bigger than everone till now
          
          if (indx==ans.size())
          {
              ans.push_back(H[i]);
          }

          // if there exist  eaual  or just greater element  that means we can repalce it by current element that is 
          just smaller than it which not create affect in the size of LIS 
          else{
              ans[indx]=H[i];
          }
          
          cout<<"size of LIS is"<<ans.size()<<endl;
      }




*/