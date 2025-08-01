using namespace std;
#include<cmath>
#include<iostream>
int main()
{
    int n;
    cin>>n;
    int dig=log10(n)+1;
    int sum=0;
    for(int i=0;i<dig;i++)
    {
        int m=n%10;
        n=n/10;
        sum=sum+pow(m,dig);
    }
    cout<<sum;
    return 0;
}