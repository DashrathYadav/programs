#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

    vector<int> rank, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void UnionByRank(int u, int v)
    {

        int sp_u = findParent(u);
        int sp_v = findParent(v);

        if (rank[sp_u] < rank[sp_v])
        {
            parent[sp_u] = sp_v;
        }
        else if (rank[sp_u] > rank[sp_v])
        {
            parent[sp_v] = sp_u;
        }
        else
        {
            parent[sp_v] = sp_u;
            rank[sp_u]++;
        }
    }
};

void parent_print(DisjointSet s,int n)
{
    
    for(int i=0;i<=7;i++)
    {
       cout<<s.findParent(i)<<" ";
    }
    cout<<endl;
}

int main()
{

    DisjointSet s = DisjointSet(7);
    s.UnionByRank(1, 2);
    s.UnionByRank(1, 3);
    s.UnionByRank(4, 5);
    s.UnionByRank(6, 7);
    s.UnionByRank(5, 6);

    if (s.findParent(3) == s.findParent(7))
    {
        cout << "Belong to same set" << endl;
    }
    else{
        cout<<"Not belong to same set"<<endl;
    }
   
   
   
    s.UnionByRank(3,7);
    
    
    
     if (s.findParent(3) == s.findParent(7))
    {
        cout << "Belong to same set" << endl;
    }
    else{
        cout<<"Not belong to same set"<<endl;
    }


    parent_print(s,7);

   
    return 0;
}