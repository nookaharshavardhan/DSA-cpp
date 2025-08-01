#include <iostream>
using namespace std;

int removeLastSetBit(int n){
    return (n & n-1);
}

int main() {
    cout<<"after removing last set bit : "<<removeLastSetBit(8);
    return 0;
}