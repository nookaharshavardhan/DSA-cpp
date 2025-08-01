#include <iostream>
#include <math.h>
using namespace std;

bool checkEligibility(long long n,bool odd){
    int num = n % 10;
    if(odd){
        if(num <= 1)return false;
        if(num <= 3)return true;
        if(num % 2 == 0 || num % 3 == 0) return false;
        for(int i = 5 ;i <= sqrt(num) ;i += 6 ){
            if (num % i == 0 || num % (i + 2) == 0)
            return false;
        }
        return true;
    }
    else{
        if(num % 2 == 0)return true;
        else false;
    }
    return false;
}


bool countGoodNumbers(long long n){
    int size = log10(n)+1;
    bool odd = (size % 2 == 0) ? false:true;
    for(int i = 0; i < size;i++){
        if(checkEligibility(n,odd)) return true;
        else return false;
        odd = !odd;
        n = n /10;
    }
    return true;
}

int main() {
    if(countGoodNumbers(7252329))cout<<"good number"<<endl;
    else cout<<" not a good number"<<endl;
    return 0;
}