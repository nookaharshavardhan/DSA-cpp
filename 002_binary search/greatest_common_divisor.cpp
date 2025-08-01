using namespace std;
#include<bits/stdc++.h>
#include<vector>
#include<iostream>
int main()
{
    int a,b;
    cin>>a>>b;
    int gcd=0;
    for(int i=1;i<=min(a,b);i++)
    {
        if(a%i==0 && b%i==0)
        {
            gcd=i;
        }
    }
    cout<<gcd<<endl;
}