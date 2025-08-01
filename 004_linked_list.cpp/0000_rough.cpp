#include <iostream>
using namespace std;

void test(){
    
    int sum{1};
    for(int i = 0; i < 5;++i){
     sum = i*10+1;
    }
    cout<<"done";
}
int main() {
   int sum{0};
   int k{0};
    test();
}