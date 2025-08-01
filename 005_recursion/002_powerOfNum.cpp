#include <iostream>
using namespace std;


double pow(double x, int n) {
    if(x == 1 || n ==0)return 1;
    double ans = 1.0;
    long n1 = n;
      if (n1 < 0) {
        n1 = -n1;
    }
    while(n1){
        if(n1%2){
            ans = ans* x;
            n1 -= 1;
        }
        else{
            x *= x;
            n1 /= 2;
        }
    }
    return ans = (n < 0)? ((double)1/(double)ans):ans;
}

double powerRecursive(double base,double ans,int exp)
{
    if(exp == 0)return ans;
    double half = powerRecursive(base,ans,exp/2);
    if(exp % 2 == 0)return base *= base; 
    return ans*base;
}

double power(double base,int exponent){
    double ans = 1;
    int exp = abs(exponent);
    ans = powerRecursive(base,ans,exp);
    return ans = (exponent < 0)? ((double)1/(double)ans):ans;
}

int main() {
    double base = 3;
    int exponent = -4;
    double result = pow(base,exponent);
    double resulty = power(base,exponent);
    cout<<result<<" "<<resulty<<endl;
    return 0;
}