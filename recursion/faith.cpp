#include<bits/stdc++.h>
using namespace std;

/*
// 1+2+3+4
ie 1234
sum(n/10)+n%10;
*/


int sum_digit(int n)
{
    if(n==0)
    return 0;

    return sum_digit(n/10)+n%10;

}

int main()
{

cout<<sum_digit(784);

}