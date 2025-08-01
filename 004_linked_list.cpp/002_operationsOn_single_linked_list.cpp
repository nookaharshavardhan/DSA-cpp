using namespace std;
#include<iostream>
#include<vector>

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

int countLL(node* head){
    int cnt = 0;
    node* mover = head;
    while(mover){
        cnt++;
        mover = mover->next;
    }
    return cnt;
}

bool search_arr(node* head,int val){
    node* mover = head;
    while(mover){
        if(mover->data == val){
            return true;
        }
        mover = mover->next;
    }
    return false;
}

void insertAtFirst(node* &head,int X){
        node* first = new node(X);
        first->next = head;
        head = first;
}
int main()
{
    vector<int> arr= {1,2,3,4,5,6,7,8};
    node* head = convertA2LL(arr);
    printLL(head);
    int size = countLL(head);
    cout<<size<<endl;
    if(search_arr(head,3)) cout<<"exists"<<endl;
    else cout<<"dosen't exists"<<endl;
    insertAtFirst(head,12);
    cout<<head->data<<endl;
    cout<<"LL after inserting ahead : ";
    printLL(head);
    return 0;
}




// | Operation             | Affects  head ? | Explanation                                                   |
// | --------------------- | --------------- | ------------------------------------------------------------- |
// | temp = head;         | ❌               | `temp` now points to same node                                |
// | temp->data = 99;     | ✅               | Changes data **in the shared node**                           |
// | temp = temp->next;   | ❌               | Only changes `temp`'s pointer                                 |
// | head->data = 5;      | ✅               | Same node is modified                                         |
// | temp = new node(20); | ❌               | `temp` now points to a **new node**, `head` remains unchanged |
