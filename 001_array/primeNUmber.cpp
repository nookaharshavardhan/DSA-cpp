#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool prime_num(const int& n){
    if (n <= 1) return false;                   
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false; 
    for(int i = 5; i <= sqrt(n);i += 6){
        if(n % i == 0)return false;
        if(n % (i+2) == 0)return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,-1);
    for(int i= 0; i < n ;++i){
            cin>>arr[i];
        }
    int sum = 0;
    for(int i = 0;i < arr.size();i++){
        if(prime_num(arr[i])) sum += arr[i];
    }
    cout<<"sum is "<<sum<<"\n";
    return 0;
}
