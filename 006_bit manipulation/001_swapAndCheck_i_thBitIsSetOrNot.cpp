#include <iostream>
using namespace std;

void swapNprint(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    cout << "a = " << a << " and b = " << b << endl;
}

bool iThBitSet(int n, int i, bool rightShift)
{
    if (rightShift && (n & (1 << i)) != 0)
        return true;
    return (((n >> i) & 1) == 1);
}

int cleariThBit(int n,int i){
    return (n & ~(1<<i) );
}


int toogleiThBit(int n ,int i){
    return (n^(i << i));
}

int main()
{
    int a = 3;
    int b = 5;
    swapNprint(a, b);
    int n = 5;
    int i = 1;
    if (iThBitSet(n, i, 0))
    {
        cout << "yes i-th bit is set" << endl;
    }
    else
        cout << "no i-th bit is not set" << endl;

    cout<<"after clearing "<<cleariThBit(42,3)<<endl;

    cout<<"after toggling i-th bit : "<<toogleiThBit(82,3)<<endl;
    return 0;
}