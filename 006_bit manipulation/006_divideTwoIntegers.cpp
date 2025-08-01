#include <iostream>
#include <limits>
using namespace std;

int divideTwoIntegers(int dividend, int divisor)
{
    if(divisor == 0)return (dividend >= 0) ? numeric_limits<int>::max() : numeric_limits<int>::min();
    //edge case for  int_Min/-1 , it results in -(INT_MIN) which causes abs(INT_MIN) a overflow ans the result should be in positive  so..... 
    if(dividend == numeric_limits<int>::min() && divisor == -1) return numeric_limits<int>::max();
    bool positive = ((dividend < 0 && divisor < 0) || (dividend >= 0 && divisor >= 0));

    int cnt = 0;
    long sum = 0;
    long absDividend = abs(static_cast<long>(dividend));
    long absDivisor = abs(static_cast<long>(divisor));


    while (absDividend >= absDivisor)
    {
        cnt = 0;
        while(absDividend >= (absDivisor << (cnt + 1 )) ){
            cnt++;
        }
        sum += 1<<cnt;
        absDividend -= (absDivisor << cnt);
    }
    if(sum >= numeric_limits<int>::max()&& positive) return numeric_limits<int>::max();
    if(sum >= numeric_limits<int>::max() && !positive) return numeric_limits<int>::min();
    return positive ? static_cast<int>(sum) : -static_cast<int>(sum);
}



int divideTwoIntegersMoreEfficientMethod(int dividend,int divisor){
    if(divisor == 0){
        return (dividend >= 0)?numeric_limits<int>::max():numeric_limits<int>::min();
    }
    if(dividend == numeric_limits<int>::min() && divisor == -1) return numeric_limits<int>::max();
    // the result will be negative only if both signs are different
    // if(true != false) negative = true;     means  (dividend >0) and (divisor smaller than 0)
    // if(true != true)  negative = false;     means  (dividend >0 ) and (divisor > 0)
    bool isNegative = ((dividend < 0) != (divisor < 0));

    long long absDividend = abs(static_cast<long long>(dividend));
    long long absDivisor =  abs(static_cast<long long>(divisor));
    long long ans = 0;
    
    for(int i = 31;i >= 0;--i){

        if(absDividend >= (absDivisor << i) ){
            absDividend -= (absDivisor << i);   // remove that chunk if it is smaller than that
            ans += (1LL << i);                  // 1 << 31 can cause overflow so..... LL
        }
    }

    if(isNegative){
        // ans is always +ve but to check the bound we do -ans
        if(-ans < numeric_limits<int>::min())return numeric_limits<int>::min();
        else return -static_cast<int>(ans);
    }
    else{
        if(ans > numeric_limits<int>::max())return numeric_limits<int>::max();
        else return static_cast<int>(ans);
    }

}



int main()
{
    int a = 1201;
    int b = 2;
    cout << "the result is : " << divideTwoIntegers(a, b);
    return 0;
}