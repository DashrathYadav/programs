/*

tabulation and memoziation form but give tle because it use O(N X N)
 use other approach in o(nlog n)

https://practice.geeksforgeeks.org/problems/7d0fa4007b8eabadc404fcc9fa917aa52982aa96/1



class Solution {

  public:
  
    int max_visiblity_possible(int indx,int h_max_indx,int h[],int n,vector<vector<int>>&dp)
    {
        if(indx >= n)
        return 0;
        
        if( dp[indx][h_max_indx] != -1)
        return dp[indx][h_max_indx];
        
        int max_cnt1=0;
        int max_cnt2=0;
        
        //let i decide to  remove current student
      max_cnt1=max_visiblity_possible(indx+1,h_max_indx,h,n,dp);
        
        // suppose i decide to keep student;
        
        if( h[indx] > h[h_max_indx])
        {
             max_cnt2=1+max_visiblity_possible( indx+1,indx,h,n,dp);
        }
        
       
        
        return dp[indx][h_max_indx]= max(max_cnt1,max_cnt2);
        
    }
    
    int tabulation(int h[],int n)
    {
        n+=1;
      
        vector<vector<int>>dp(n+2,vector<int>(n+1,-1));
        
        for(int indx=n;indx>=1;indx--)
        {
            for(int h_max_indx=n-1;h_max_indx >=0;h_max_indx--)
            {
                 int max_cnt1=0;
        int max_cnt2=0;
        
        //let i decide to  remove current student
      max_cnt1=dp[indx+1][h_max_indx];
        
        // suppose i decide to keep student;
        
        if( h[indx] > h[h_max_indx])
        {
             max_cnt2=1+dp[indx+1][indx];
        }
 
         dp[indx][h_max_indx]= max(max_cnt1,max_cnt2);
            }
        }
        
        return dp[1][0];
    }
    
  
    int removeStudents(int H[], int N) {
        // code here
       
        int h[N+1];
        h[0]=0;
        for(int i=0;i<N;i++)
        h[i+1]=H[i];
  
  //return tabulation(h,N);
   int  n=N+1;    
        vector<vector<int>>dp(n,vector<int>(n,-1));
       int sees= max_visiblity_possible(1,0,h,n,dp);
  
                
        
        
       return N-sees;
        
        
    }
};
*/