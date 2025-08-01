#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
    node(int val){      // constructor
        data = val;
        next =nullptr;
        prev = nullptr;
    }
};

node* convert_arr_to_2DLL(vector<int> arr){
    if(arr.empty())return nullptr;
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
    if(head == nullptr) cout<<"the LL is empty";
    node* mover = head;
    while(mover != NULL){
        cout<<mover->data<<" ";
        mover = mover->next;
    }cout<<endl;
}

void delAlloccurancesInDLL(node** head ,int  key){
    node* mover = *head;
    node* nextNode = nullptr; 
    node* temp = nullptr;
    while(mover){
        if(mover->data == key){
            if(mover->prev == nullptr){
                *head = mover->next;
                if(*head){
                    (*head)->prev = nullptr;
                }
                temp = mover;
                mover = mover->next;
                delete temp;
            }
            else if(mover->next == nullptr){
                mover->prev->next = nullptr;
                temp = mover;
                mover = nullptr;
                delete temp;
            }
            else{
                mover->prev->next = mover->next;
                mover->next->prev = mover->prev;
                temp = mover;
                mover = mover->next;
                delete temp;
            }
        }
        else{
            mover = mover->next;
        }
    }
}
int main() {
    vector<int> arr{};
    node* head = convert_arr_to_2DLL(arr);
    delAlloccurancesInDLL(&head, 2);
    printLL(head);
    return 0;
}