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

int main() {
    queue q;
    q.push(31);
    q.push(99);
    cout<<"top element is "<<q.top()<<endl;
    cout<<"size is "<<q.size()<<endl;
    q.pop();
    cout<<"top element is "<<q.top()<<endl;
    cout<<"size is "<<q.size()<<endl;
    return 0;
}