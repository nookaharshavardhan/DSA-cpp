#include <iostream>
#include <vector>
using namespace std;


//        int applyOperator(int a,char op, int b) {
//            switch(op) {
//                case '#': return a*10 + b;
//                case '+': return a + b;
//                case '-': return a - b;
//                case '*': return a * b;
//            }
//        }
       
//        void generate(const string & arr,vector<string>& ans,int total,string temp,int i,int target, vector<char>& ops){
//            if(i == arr.size()){
//                if(total == target)  ans.push_back(temp);
//                return ;
//            }
//            int num = arr[i] - '0';
       
//            for(int op = 0; op < 4; op++){
//                string next = temp;
//                if(ops[op] == '#'){
//                    next = next + arr[i];
//                }
//                else next = next + ops[op] + arr[i];
//                generate(arr,ans,applyOperator(total,ops[op],num),next,i+1,target,ops);
//            }
//        }
       
       
//        vector<string> placeOperator(string arr,int target){
//            vector<string> ans;
//            int total = arr[0]-'0';
//            string temp = string("")+arr[0];
//            vector<char> ops = {'+','-','*','#'};
//            generate(arr,ans,total,temp,1,target,ops);
//            return ans;
//        }



void generate(string& arr,vector<string>& ans,int total ,string temp,int target,int lastNum,int pos){
    if(pos == arr.size()){
        // cout <<"int the function :-"<< temp << " = " << total << endl;
        if(total == target)ans.push_back(temp);
        return ;
    }
    
    for(int i = pos ; i < arr.size(); i++){

        if(i != pos && arr[pos] == '0')break;
        string part = arr.substr(pos,i - pos + 1);
        int  num = stoi(part);
        
        if(pos == 0){
            generate(arr,ans,num,part,target,num,i+1);
        }
        else{
            generate(arr,ans,total+num,temp + '+' + part,target,num,i+1);
            generate(arr,ans,total-num,temp+'-'+part,target,-num,i+1);
            generate(arr,ans,total - lastNum + lastNum*num,temp+'*'+part,target,lastNum*num,i+1);
        }
    }
}

vector<string> placeOperator1(string arr, int target){
    vector<string> ans;
    generate(arr,ans,0,string(""),target,0,0);
    return ans;
}


int main() {
    string arr = "232";
    string arr1 = "3022";
    int target = 8,target1 = 8;
    vector<string> ans = placeOperator1(arr,target);
    for(auto it : ans){
        cout<<it<<endl;
    }
    cout<<"3022"<<endl;
    vector<string> ans1 = placeOperator1(arr1,target1);
    for(auto it : ans1){
        cout<<it<<endl;
    }
    return 0;
}