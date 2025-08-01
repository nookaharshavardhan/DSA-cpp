using namespace std;
#include<iostream>
int main()
{
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
   {
        cin>>arr[i];
   }

   // PRECUMPUTING
   int hashing[13]={0};
   for(int i=0;i<n;i++)
   {
        hashing[arr[i]]+=1;
   }

   int no_of_queries;
   cin>>no_of_queries;
   int query;
   while(no_of_queries--)
   {
    cin>>query;
    cout<<hashing[query];
   }
}