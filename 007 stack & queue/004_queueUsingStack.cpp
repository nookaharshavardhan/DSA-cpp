#include <iostream>
using namespace std;

class stack{
    int * arr;
    int top_;
    public:
        stack(){
            top_ = 0;
            arr = new int[1000];
        }
        ~stack(){
            delete[] arr;
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

void push_(stack & s,int x){
    stack temp;
    for(int i =0 ;i < s.size() ; ++i){
        temp.push(s.pop());
    }
    s.push(x);
    for(int i = 0; i < temp.size();i++){
        s.push(temp.pop());
    }
}
int main() {
    stack s;
    push_(s,3);
    push_(s,4);
    push_(s,99);
    push_(s,77);
    s.pop();
    cout<<"1 top of the queue is "<<s.top()<<" and size is "<<s.size()<<endl;

    stack s1;
    s1.push(3);
    s1.push(4);
    s1.pop();
    cout<<"2 top of the stack "<<s1.top()<<endl;
    return 0;
}