#include <iostream>
using namespace std;

int XORof1_to_n(int n){
    if(n % 4 == 1)return 1;
    if(n%4 == 2)return n+1;
    if(n%4 == 3)return 0;
    if(n%4 == 0)return n;
    return -1;
}

int XORofRange(int left,int right){
    return (XORof1_to_n(left - 1)) ^ (XORof1_to_n(right));
}

int main() {
    int left = 4;
    int right = 25;
    cout<<XORofRange(left,right);
    return 0;
}