#include<bits/stdc++.h>
using namespace std;

priority_queue<int ,vector<int >,greater<int>>pqmin;
priority_queue<int ,vector<int >>pqmax;

void insert(int num)
{
    if(pqmax.size()==pqmin.size()){
       // cout<<"1"<<endl;
        if(pqmin.size()==0)
        {pqmax.push(num);
        return ;
        }

        if(num >pqmax.top())
        pqmin.push(num);

        else pqmax.push(num);

    }
    else if(pqmax.size() > pqmin.size()){
         if(pqmin.size()==0)
         {
             pqmin.push(num);
             return;
         }

         
        if(pqmin.top() > num)
        {
            int temp=pqmax.top();
            pqmax.pop();
            pqmax.push(num);
            pqmin.push(temp);

        }
        else pqmin.push(num);
    }
    else{

        // cout<<"3"<<endl;
          if(pqmax.top() < num)
        {
            int temp=pqmin.top();
            pqmin.pop();
            pqmax.push(temp);
            pqmin.push(num);

        }
        else pqmax.push(num);
    }
}

void median()
{
    if(pqmax.size()==pqmin.size())
  {  float x=pqmax.top()+pqmin.top();
    x=x/2;
    cout<<x<<endl;
  }

    else if(pqmax.size() < pqmin.size())
    cout<<pqmin.top()<<endl;

    else cout<<pqmax.top()<<endl;


}

int main()
{
insert(10);
median(); 
insert(15);
median();   
insert(21);
median();
insert(30);
median();
insert(18);
median();
insert(19);
median();
    
}