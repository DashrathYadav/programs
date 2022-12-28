/*
1. You are given a number n, representing the number of stairs in a staircase.
2. You are on the 0th step and are required to climb to the top.
3. You are given n numbers, where ith element's value represents - till how far from the step you 
     could jump to in a single move.  
     You can of course jump fewer number of steps in the move.
4. You are required to print the number of different paths via which you can climb to the top.
Input Format
A number n
.. n more elements
Output Format
A number representing the number of ways to climb the stairs from 0 to top.
Question Video

  COMMENTConstraints
0 <= n <= 20
0 <= n1, n2, .. <= 20
Sample Input
10
3
3
0
2
1
2
4
2
0
0
Sample Output
5
*/

#include<bits/stdc++.h>
using namespace std;


int  using_recursion(int n,vector<int>Possible_jumps,int stair_no)
{
    if(stair_no==n)
    return 1;

    if(stair_no > n)
    return 0;
    int cnt_ways=0;
        for(int j=1;j<=Possible_jumps[stair_no];j++)
        {
            cnt_ways+= using_recursion(n,Possible_jumps,stair_no+j);
        }
        cout<<"for "<< stair_no<< "ans is"<<cnt_ways<<endl;
        return cnt_ways;
}


void using_dp(int n,vector<int>Possible_jumps)
{

vector<int>dp(n+1,-1);
    dp[n]=1;

    for(int i=n-1;i>=0;i--)
    {
        int stair_ways=0;
        for(int j=1;j<=Possible_jumps[i];j++)
        {
            if(i+j <=n)
            {
                stair_ways+=dp[i+j];
            }

        }

        dp[i]=stair_ways;
    }

    for(auto it: dp)
    cout<<it<<" ";
    cout<<endl;

    cout<<dp[0]<<endl;



}

int main()
{

    int n;
    cin>>n;
    vector<int>Possible_jumps(n+1,0);
    for(int i=0;i<=n;i++)
    {
        cin>>Possible_jumps[i];
    }
    cout<<"ans using dp"<<endl;
    using_dp(n,Possible_jumps);

    cout<<"ans using recursion"<<endl;
    cout<<using_recursion(n,Possible_jumps,0)<<endl;



    
 return 0;
}