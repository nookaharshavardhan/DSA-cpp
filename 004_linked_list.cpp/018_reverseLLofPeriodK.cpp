#include <iostream>
#include<vector>
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
    if(arr.empty())return nullptr;
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
    if(head == nullptr) cout<<"the LL is empty";
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


node* reverseLLofPeriodK(node* head,int k){
    if(k == 1 || head == nullptr)return head;
    node* mover = head;
    node* st = nullptr;
    node* temp = nullptr;
    node* lastTail = nullptr;
    node* newHead = nullptr;
    node* reversedHead = nullptr;
    while(mover){
        int cnt = 1;
        st = mover;
        while(mover && cnt < k){    //iterate to 3rd element
            mover = mover->next;
            cnt++;
        }
        if(cnt == k && mover != nullptr){
            temp = mover->next;                           //storing first element of next period
            mover->next = nullptr;                        // unlink the tail of the period
            reversedHead = reverseList(st);               
            if(!newHead) newHead  = reversedHead;     // new head of reversed main LL
            st->next = temp;
            if(lastTail != nullptr) {
                lastTail->next = reversedHead;
            }
            lastTail = st;
            mover = temp;
        }
        else{     //skiplast non divisible set of numbers

            break;
        }
    }
    return newHead ? newHead : head;
}

int main() {
    vector<int> arr= {1,2,3,4,5,6,7,8};
    node* head = convertA2LL(arr);
    printLL(head); 
    head = reverseLLofPeriodK(head,3);
    printLL(head); 
    return 0;
}

        // cout<<" after first reverse - mover : "<<mover->data<<endl;
        // cout<<"st : "<<st->data<<endl;
        // cout<<"newhead : "<<newHead->data<<endl;
        // cout<<"reversehead : "<<reversedHead->data<<endl;
        // if(lastTail) cout<<"lasttail : "<<lastTail->data<<endl;
        // cout<<"temp : "<<temp->data<<endl;
        // cout<<"head : "<<head->data<<endl;