using namespace std;
#include<cmath>
#include<iostream>
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            cout<<i<<" ";
            if((n/i)!=i)cout<<(n/i)<<" ";
        }
    }

    return 0;
}