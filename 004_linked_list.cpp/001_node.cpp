using namespace std;
#include<iostream>

struct node{
    int data;
    node* ptr;

    node(int data1){
        data = data1;
        ptr = nullptr;
    }
};
int main()
{
    node index1(10);
    node index2(132);
    index1.ptr = &index2;
    //or
    node* first = new node(99);
    first->ptr = new node(77);
    return 0;
}



//                           index1 ──► [10 | ptr ──► index2]
//                           index2 ──► [132 | nullptr]



//                           first ──► [99 | ptr ──► [77 | nullptr]]
