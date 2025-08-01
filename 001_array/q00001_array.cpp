using namespace std;
#include<bits/stdc++.h>
#include<iostream>
int main()
{
    unordered_set<int> s;
    s={1,2,3,4,57,6,6,6,5,3};
    int d=distance(s.begin(),s.end());
    cout<<d<<endl;

    if(s.find(7)!=s.end())
    cout<<"true"<<endl;
    else cout<<"false"<<endl;
    int i=s.count(20);
    cout<<i;

    return 0;
}