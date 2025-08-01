#include <iostream>
using namespace std;

int countSetBits(int n){
    int cnt = 0;
    while(n != 0){

        // For bits to the left of the original rightmost set bit: These bits are identical in both n and n-1. So, 1 & 1 is 1, and 0 & 0 is 0. They remain unchanged. No '1's here are flipped to '0's.
        n = n & (n-1);
        cnt++;
    }
    return cnt;
}


int main() {
    cout<<"no of set bits are : "<<countSetBits(56);    
    return 0;
}