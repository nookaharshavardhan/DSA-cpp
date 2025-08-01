using namespace std;
#include<iostream>
#include<vector>

void swap(int& first ,int& second)
{
    int temp=first;
    first=second;
    second=temp;
}
int main()
{
     int a=3;
     int b=4;

     swap(a, b);
     cout<<a<<" "<<b<<endl;

     vector<int>v={1,2,3,4,5,6,7,8,9};
     for(auto& i:v)
        i+=5;
    for(auto i:v)
        cout<<i<<" ";

    return 0;
}