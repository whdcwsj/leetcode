#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(n%2==1){
        cout<<0<<endl;
        return 0;
    }
    unordered_map<char,char>record={{')','('},{']','['},{'}','{'}};
    stack<char>wang;
    bool flag=true;
    for(char temp:s){
        if(record.count(temp)){
            if(wang.empty()|| wang.top()!=record[temp]){
                flag=false;
                break;
            }
            wang.pop();
        }else{
            wang.push(temp);
        }
    }
    if(!wang.empty()){
        flag=false;
    }
    if(flag==true){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }

    system("pause");
    return 0;
}