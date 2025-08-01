using namespace std;
#include<iostream>
int main()
{
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    //PRECOMPUTING
    int hashing[26]={0};
    for(int i=0;i<n;i++)
    {
       
        hashing[arr[i]-'a']+=1;
    }

    int no_of_queries;
    cin>>no_of_queries;
    char query;
    while(no_of_queries--)
    {
    
    cin>>query;
    cout<<hashing[query-'a'];
    }
    return 0;
}