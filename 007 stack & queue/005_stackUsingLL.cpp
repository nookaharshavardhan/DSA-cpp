#include <iostream>
using namespace std;


struct node{
    int data;
    node* next;
    node(int x):data(x),next(nullptr){}
};

class lls{
    node* head;
    node* tail;
    int size;
    public:
        lls(){
            head = nullptr;
            tail = nullptr;
            size = 0;
        }
        void push(int x){
            if(tail == nullptr){
                node* temp = new node(x);
                temp->next = nullptr;
                head = temp;
                tail = temp;
            }
            else{
                node* temp = new node(x);
                temp->next = head;
                head = temp;
            }
            size++;
        }
        int pop(){
            if(head == nullptr){
                throw out_of_range("there is no elements to pop ");
            }
            node* temp = head->next;
            delete head;
            head = temp;
            size--;
            return head->data;
        }
        bool isEmpty(){
            return head == nullptr;
        }
        int top(){
            if(head == nullptr){
                throw out_of_range("there is no elements to peek ");
            }
            return head->data;
        }
        void print(){
            node* mover = head;
            while(mover != nullptr){
                cout<<mover->data<<" ";
                mover = mover->next;
            }cout<<endl;
        }
};


int main() {
    lls s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.pop();
    cout<<s.top()<<endl;
    s.print();
    return 0;
}