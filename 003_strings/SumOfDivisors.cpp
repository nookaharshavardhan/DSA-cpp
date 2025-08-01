#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    int n=5;
    int sum=0;
        for(int j=1;j<=n;j++){
            for(int i=1;i<=sqrt(j);i++)
            {
                if(j%i==0)
                {
                    sum+=i;
                    if(i!=j/i)
                    {
                        sum+=j/i;
                    }
                }
                
            }
            cout<<sum<<" ";
        }
    return 0;
}