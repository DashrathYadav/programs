#include<bits/stdc++.h>
using namespace std;

void heapify(int *a,int pos,int last)
{
    int left;
    int right;
    int greatest=pos;
    if(2*pos+1 <= last)
    {
        left=(pos*2)+1;
        right=(pos*2)+2;
        if(left<=last)
        if(a[greatest] < a[left])
        greatest=left;

        if(right<=last)
        if(a[greatest] <a[right])
        greatest=right;


        if(greatest !=pos)
        {
            swap(a[pos],a[greatest]);
          
            heapify(a,greatest,last);
        }
        

    }
     
}

void heapsort(int *a,int last)
{
    swap(a[last],a[0]);
    heapify(a,0,last-1);

}

int main()
{

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
cin>>a[i];

int last= ((n-1)-1)/2;
for(int i=last;i>=0;i--)
{
    heapify(a,i,n-1);
}
    // heapify(a,last,n-1);

for(int i=0;i<n;i++)
cout<<a[i]<<" ";

for(int i=n-1;i>=0;i--)
heapsort(a,i);
cout<<endl;
for(int i=0;i<n;i++)
cout<<a[i]<<"  ";

}