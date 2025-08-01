using namespace std;
#include<vector>
#include<iostream>
int main()
{
     int n=2446;
     int count=0;
     int real_n=n;
     while(n>0){
        int m=n%10;
        if(real_n%m==0 && m!=0){
            count++;
        }
        n/=10;
     }
     cout<<count;

    return 0;
}