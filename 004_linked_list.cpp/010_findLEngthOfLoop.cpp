#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    node* next;
    node(int data_){
        data = data_;
        next = nullptr;
    }
};

node* convertA2LL(vector<int>arr){
    if(arr.empty()) return nullptr;
    int n = arr.size();
    node* head = new node(arr[0]);
    node* mover = head;
    node* start = nullptr;
    int cnt = 0 ;
    for(int i = 1; i < arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        cnt++;
        if(cnt == n/2){
            start = mover;
        }
        else if(cnt == n-1){
            mover->next->next = start;
        }
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


int findLengthOfLoop(node* head){
    node* fast = head;
    node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            int cnt = 1;
            while(slow->next != fast){
                slow = slow->next;
                cnt++;
            }
            return cnt;
        }
    }
    return 0;
}


int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    node* head = convertA2LL(arr);
    // printLL(head);
    int x = findLengthOfLoop(head);
    cout<<x<<" "<<endl;
    return 0;
}