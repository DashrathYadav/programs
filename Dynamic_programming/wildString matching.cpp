//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool wildCardMatch(int i, int j, string s1, string s2)
    {

        // cout<<i<<" "<<j<<endl;
        if (i < 0 && j < 0)
            return true;

        if (j < 0)
        {
            for (int p = i; p >= 0; p--)
            {
                if (s1[p] != '*')
                    return false;
            }
            return true;
        }

        if (i < 0)
            return false;

        if (s1[i] == s2[j] || s1[i] == '?')
        {
            return (wildCardMatch(i - 1, j - 1, s1, s2));
           
        }
        else if (s1[i] == '*')
        {
             if(wildCardMatch(i - 1, j, s1, s2) || (wildCardMatch(i - 1, j - 1, s1, s2)))
             return 1;

            for (int k = j - 2; k >= 0; k--)
            {
                if (wildCardMatch(i, k, s1, s2))
                    return true;
            }

            return false;
        }
        else
        {
            return false;
        }
    }
    
    
    /*You are required to complete this method*/
    int wildCard(string pattern, string str)
    {
        // cout<<"start"<<endl;
     
       return wildCardMatch(pattern.size() - 1, str.size() - 1, pattern, str);
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends