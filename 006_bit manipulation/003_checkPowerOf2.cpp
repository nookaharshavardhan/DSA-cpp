#include <iostream>
using namespace std;

bool checkPowerOf2(int n){
    return ((n & (n-1)) == 0);
}

int main() {
    if(checkPowerOf2(31)){
        cout<<"yes it is power of two "<<endl;
    }
    else{
        cout<<"no it is not a power of 2 "<<endl;
    }
    return 0;
}