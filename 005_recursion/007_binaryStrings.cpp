#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void generate(vector<string> &arr, int n ,string s){
    if(s.length() == n){
        arr.push_back(s);
        return ;
    }
    generate(arr,n,s+'0');
    if(s.back() != '1'){
        generate(arr,n,s+'1');
    }
}

vector<string> binaryStrings(int n){
    vector<string> arr;
    generate(arr,n,"");
    return arr;
}


vector<string> binraryStringsQueue(int n){
    vector<string> res;
    queue<string>que;
    que.push("");
    while(!que.empty()){
        string current = que.front();
        que.pop();

        if(current.length() == n){
            res.push_back(current);
            continue;
        }

        que.push(current + "0");

        if(current.empty() || current.back() != '1'){
            que.push(current + '1');
        }
    }
    return res;
}
int main() {
    vector<string> arr = binaryStrings(3);
    for(auto it : arr){
        cout<<it<<endl;
    }

    vector<string> arr1 = binraryStringsQueue(3);
    cout<<"bu queue : "<<endl;
     for(auto it : arr1){
        cout<<it<<endl;
    }
    return 0;
}