#include <iostream>
#include <climits>
using namespace std;


int recursiveAtoi(string str, long sum, int i, int sign, bool signIsSet) {
    if (i >= str.size()) return (int)(sum * sign);

    if (str[i] == ' ' && !signIsSet)
        return recursiveAtoi(str, sum, i + 1, sign, signIsSet);

    if (!signIsSet && (str[i] == '+' || str[i] == '-')) {
        sign = (str[i] == '-') ? -1 : 1;
        signIsSet = true;
        return recursiveAtoi(str, sum, i + 1, sign, signIsSet);
    }

    if (str[i] >= '0' && str[i] <= '9') {
        signIsSet = true;
        int num = str[i] - '0';

        if (sum*10 + num > INT_MAX) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        sum = sum * 10 + num;
        return recursiveAtoi(str, sum, i + 1, sign, signIsSet);
    }

    return (int)(sum * sign);
} 

int atoi(string s){
    long sum = 0;
    int i = 0;
    int sign = 1;
    bool signIsSet = false;
    return recursiveAtoi(s,sum,i,1,signIsSet);
}

int main() {
    string chars ="2147483646";
    cout<<INT_MAX<<endl;
    int num  = atoi(chars);
    cout<<num<<endl;
    return 0;
}