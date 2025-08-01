#include <iostream>
#include <math.h>
using namespace std;

#define MOD 1000000007

long long power(long long x, long long n) {
    if(x == 1 || n ==0)return 1;
    long long ans = 1;
    x =x% MOD;
    long long exp = abs(n);
    while(exp){
        if (exp % 2) ans =(ans* x)%MOD;
        x = (x*x)%MOD;
        exp /= 2;
    }
    return ans;
}

int countGoodNumbers(long long n) {
    long long even = (n+1)/2;
    long long odd = n/2;    // 3 2 3 2 3 2
    long long a = power(4,odd)%MOD;
    long long b = power(5,even)%MOD;
    return (int)((a*b)% MOD);
}

int countGOodNUmberUsingRecursion(int pos ,long long n){
    if(pos == n)return 1;
    long long indices = (pos%2 == 0)?5:4;
    return indices*countGOodNUmberUsingRecursion(pos+1,n);
}

int main() {
    int y = countGoodNumbers(4);
    int x = countGOodNUmberUsingRecursion(0,4);
    cout<<x<<" "<<y<<endl;
    return 0;
}
