#include <iostream>
using namespace std;

class queue{
    int end;
    int start;
    int * arr;
    public:
        ~queue(){
            delete[] arr;        // should be delete[] not just "delete" cause we have used arr[] 
        }
        queue(){
            end = 0;
            start = 0;
            arr = new int[100];
        }
        void push(int x){
            arr[end++] = x;
        }
        int pop(){
            int x = arr[start++];
            return x;
        }
        int top(){
            return arr[start];
        }
        int size(){
            return end - start;
        }
};

void push_(queue & q,int x){
    queue q1;
    q1.push(x);
    int n = q.size();
    for(int i = 0; i < n;i++){
        q1.push(q.pop());
    }
    n = q1.size();
    for(int i = 0 ;i < n;i++){
        q.push(q1.pop());
    }
}

int main() {
    queue q;
    push_(q,3);
    push_(q,5);
    push_(q,9);
    q.pop();
    cout<<"top is "<<q.top()<<endl;
    return 0;
}