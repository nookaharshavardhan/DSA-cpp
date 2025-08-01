#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sqrt(i);j++)
		{
			if((i%j)==0)sum+=j;
			if((i/j)!=j)sum+=(i/j);
           
		}
      
	}
    cout<<sum<<" ";
    


    return 0;
}