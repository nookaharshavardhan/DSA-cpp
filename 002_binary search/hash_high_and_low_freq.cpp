using namespace std;
#include<vector>
#include<iostream>
#include<map>
int main()
{
    int high_freq_value=0, high_freq_num=0,low_freq_num=0,low_freq_value=9999;
    vector<int>arr={10,5,10,15,10,5,10,10};
    int n=arr.size();
    map<int,int>mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }
    for(auto i:mpp)
    {
        if(i.second>high_freq_value){
            high_freq_value=i.second;
            high_freq_num=i.first;
        }
        if(i.second<low_freq_value){
            low_freq_value=i.second;
            low_freq_num=i.first;
        }

    }
    cout<<high_freq_num<<" repeated "<<high_freq_value<<" times"<<endl;
    cout<<low_freq_num<<" repeated "<<low_freq_value<<" times";
    return 0;
}