#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    node* next;

    node(int data1){
        data = data1;
        next = nullptr;
    }
};

node* convertA2LL(vector<int>arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}


void printLL(node* head){
    node* mover = head;
    while(mover != NULL){
        cout<<mover->data<<" ";
        mover = mover->next;
    }cout<<endl;
}

node* reverseList(node* head) {
   node* mover = head; 
   node* back = nullptr;
   node* front = nullptr;
   while(mover){
        front = mover->next;
        mover->next = back;
        back = mover;
        mover = front;
   }
   return back;
}

bool checkIfPalindrome(node* head){
    node* fast = head;
    node* slow = head;
    while(fast->next != nullptr && fast->next->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
    }
    node* fst = head;
    node* sec = reverseList(slow->next);
    while(sec != nullptr){
        if(sec->data == fst->data){
            sec = sec->next;
            fst = fst->next;
        }
        else{
            return false;
        }
    }
    node* temp = reverseList(slow->next);
    return true;
}
int main() {
    vector<int> arr = {2,1,2};
    node* head = convertA2LL(arr);
    printLL(head);
    if(checkIfPalindrome(head)){
        cout<<"true";
    }
    else cout<<"false";
    return 0;
}