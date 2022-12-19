
//TC=4*alpha     i.e as good as good as constant  huge derative


#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    vector<int> size, parent;
    int N;
public:
    DisjointSet(int n)
    {
        N=n;
        size.resize(N + 1,1);
        parent.resize(N + 1);

        for (int i = 0; i <= N; i++)
            parent[i] = i;
    }

    int findParent(int u)
    {
        if (parent[u] == u)
            return u;

        return parent[u] = findParent(parent[u]);
    }

    void UnionBySize(int u, int v)
    {

        int sp_u = findParent(u);
        int sp_v = findParent(v);

            if(sp_u==sp_v)
            return ;

        if (size[sp_u] < size[sp_v])
        {
            parent[sp_u] = sp_v;
            size[sp_v]+=size[sp_u];

        }
        else if (size[sp_u] >= size[sp_v])
        {
            parent[sp_v] = sp_u;
            size[sp_u]+=size[sp_v];
        }
        
    }

    void print_size(){

        for(int i=0;i<=N;i++)
        {
            cout<<size[i]<<" ";
        }
        cout<<endl;
    }


void parent_print()
{
    
    for(int i=0;i<=N;i++)
    {
       cout<<findParent(i)<<" ";
    }
    cout<<endl;
}

};


int main()
{

DisjointSet s = DisjointSet(7);
    s.parent_print();
cout<<endl;
s.print_size();

    
    s.UnionBySize(1, 2);
    s.UnionBySize(1, 3);
    s.UnionBySize(4, 5);
    s.UnionBySize(6, 7);
    s.UnionBySize(5, 6);

    if (s.findParent(3) == s.findParent(7))
    {
        cout << "Belong to same set" << endl;
    }
    else{
        cout<<"Not belong to same set"<<endl;
    }
   
   
   
    s.UnionBySize(3,7);
    
    
    
     if (s.findParent(3) == s.findParent(7))
    {
        cout << "Belong to same set" << endl;
    }
    else{
        cout<<"Not belong to same set"<<endl;
    }


     s.parent_print();
cout<<endl;
s.print_size();   
   
    return 0;
}