#include<bits/stdc++.h>
using namespace std;


int check(int a,int f[],int n){
for(int i=0;i<n;i++){
    if(a==f[i]){
        return 1;
    }
}
return 0;
}


int opt(int rs[],int f[],int n,int fs,int ptr){
    int i,j,max=0,current_pos=n,idx;
    
    for( j=0;j<fs;j++){
    for( i=ptr;i<n;i++){
            if(f[j]==rs[i])
            {
                current_pos=i;
                break;    
            }

        }
        if(current_pos > max){
            max=current_pos;
            idx=j;
        }
    }
    return j;
}


int main(){
    int rs[100],f[10],fs,n,fault=0,pagehit=0;
    cout<<"Enter refrence string size"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>rs[i];
    }
    cout<<"enter the size of frame"<<endl;
    cin>>fs;
    int fidx;
    for(int i=0;i<fs;i++){
        cin>>f[i];
    }
    for(int i=0;i<n;i++){
       
       if(check(rs[i],f,fs)){
          pagehit++;
       }
       else{
           fault++;
           fidx=opt(rs,f,n,fs,i+1);
           f[fidx]=rs[i];
       }

        for(int i=0;i<fs;i++){
            cout<<f[i]<<" ";
        }
        cout<<endl;

    }
    cout<<"page fault is"<<fault<<endl;
    cout<<"page hit is"<<pagehit<<endl;
}