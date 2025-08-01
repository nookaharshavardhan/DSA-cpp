using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

struct ListNode {
  int val;
  struct ListNode * next;
  ListNode(int x) {
    val = x;
    next = NULL;
  }
}; 




ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(head == nullptr || head->next == nullptr) return nullptr;
    ListNode* mover = head;
    int size = 0;
    int cnt = 0;
    while(mover){
        size++;
        mover = mover->next;
    }
    mover = head;
    if(size == n){
        ListNode* temp = head;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    while(mover && cnt != size -n-1){
        cnt++;
        mover = mover->next;
    }
    ListNode* temp = mover->next;
    
    mover->next = temp->next;
    mover = nullptr;
    temp = nullptr;
    return head;
}

ListNode* convertA2LL(vector<int>arr){
    ListNode* head = new ListNode(arr[0]);
    ListNode* mover = head;
    for(int i = 1; i < arr.size(); i++){
        ListNode* temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printLL(ListNode* head){
    ListNode* mover = head;
    while(mover != NULL){
        cout<<mover->val<<" ";
        mover = mover->next;
    }cout<<endl;
}

int main(){
    vector<int> arr= {1,2,3,4,5};
    ListNode* head = convertA2LL(arr);
    head = removeNthFromEnd(head,2);
    printLL(head);
}