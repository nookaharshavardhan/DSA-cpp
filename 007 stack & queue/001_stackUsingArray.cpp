#include <iostream>
#include<stdexcept>
using namespace std;

class stack{
    int * arr;
    int top_;
    public:
        stack(){
            top_ = 0;
            arr = new int[1000];
        }
        void push(int x){
            if(top_ == 999) throw overflow_error("exceeded array size ");    
            arr[top_++] = x;
        }
        int pop(){
            if(top_ == 0) throw out_of_range("array is empty ");
            int x = arr[--top_];
            return x;
        }
        int top(){
            if(top_ == 0){
                throw invalid_argument("array is empty");
            }
            return arr[top_ - 1];
        }
        int size(){
            return top_;
        }
};

int main() {
    stack s;
    s.push(31);
    cout<<"1 top elem is "<<s.top()<<endl;
    s.pop();
    s.push(99);
    s.push(99999);
    cout<<"2 top elem is "<<s.top()<<endl;
    cout<<"size is "<<s.size()<<endl;
    return 0;
}