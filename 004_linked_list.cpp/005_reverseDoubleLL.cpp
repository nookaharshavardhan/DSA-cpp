#include<iostream>
#include<vector>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
    node(int dat){
        data = dat;
        next = nullptr;
        prev = nullptr;     
    }
};

node* convert_arr_to_2DLL(vector<int> arr){
    if(arr.empty()) return nullptr;
    
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }
    return head;
}

void printLL(node* head){
    node* mover = head;
    while(mover != NULL){
        cout << mover->data << " ";
        mover = mover->next;
    }
    cout << endl;
}

node* reverseDLL(node* head){
    node* mover = head;
    node* last;
    while(mover){
        last = mover->next;
        mover->next = mover->prev;
        mover->prev = last;
        if(last == nullptr){
            head = mover;
        }
        mover = last;
    }
    return head;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,6};
    node* head = convert_arr_to_2DLL(arr);
    // printLL(head);
    head = reverseDLL(head);
    printLL(head);
    node* temp;
    while(head){
        temp = head;
        head = head->next;
        delete temp;
    }
    return 0;
}