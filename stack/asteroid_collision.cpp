/*
Link :-https://practice.geeksforgeeks.org/problems/asteroid-collision/1
We are given an integer array asteroids of size N representing asteroids in a row. For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are of same size, both will explode. Two asteroids moving in the same direction will never meet.
 

Example 1:

Input:
N = 3
asteroids[ ] = {3, 5, -3}
Output: {3, 5}
Explanation: The asteroid 5 and -3 collide resulting in 5. The 5 and 3 never collide.
Example 2:

Input:
N = 2
asteroids[ ] = {10, -10}
Output: { }
Explanation: The asteroid -10 and 10 collide exploding each other.
Your Task:
You don't need to read input or print anything. Your task is to complete the function asteroidCollision() which takes the array of integers asteroids and N as parameters and returns the state of asteroids after all collisions.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 ≤ N ≤ 105
-1000 ≤ asteroidsi  ≤ 1000
asteroids[i]!=0
*/
// input
//   9
// 3 -15 -2 2 -9 1 8 2 -2

// output -`5 -2 -9 1 8.

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &a) {
        // code here
        stack<int>s;
        int i=0;
        for(int i=0;i<N;i++)
        {
            if(s.empty())
            {
                s.push(a[i]);
                
            }
           else {
               if( s.top() < 0)
               {
                   s.push(a[i]);
               }
               else if( s.top() > 0 && a[i] > 0)
               {
                   s.push(a[i]);
               }
               else{
                   
                   while( !s.empty() && (s.top()> 0 && a[i] < 0)  &&  ( abs(s.top()) < abs(a[i])) )
                   {
                       s.pop();
                       
                   }
                   
                   if(!s.empty() && (s.top()> 0 && a[i] < 0)  && abs(s.top())==abs(a[i]))
                   {
                       s.pop();
                       continue;
                   }
                   else if(!s.empty()  && (s.top()> 0 && a[i] < 0) && (abs(s.top()) > abs(a[i]) ) )
                   {
                       continue;
                   }
                   
                   s.push(a[i]);
                   
               }
                
            }
         
        }
        

        
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends