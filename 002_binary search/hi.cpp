using namespace std;
#include<iostream>
int main()
{
     int n=5;
     
     for(int i=1;i<n;i++)
     {
        int start=1;
        for(int j=1;j<=i;j++)
        {
            cout<<start<<" ";
            start+=1;
        }
        cout<<endl;
     }
    return 0;
}