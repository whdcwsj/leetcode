#include<bits/stdc++.h>
using namespace std;

//阶乘函数
unsigned long long jiecheng(int n){
    unsigned long long res=1;
    for(int i=1;i<=n;i++){
        res*=i;
    }
    return res;
}


int main(){
    string s;
    cin>>s;
    unsigned long long length=s.size();
    unsigned long long temp=1;
    unordered_map<char,int>wang;
    for(char& c:s){
        wang[c]++;
    }
    for(int j=0;j<wang.size();j++){
        if(wang[j]>1){
            temp*=jiecheng(wang[j]);
        }
    }

    cout<<jiecheng(length)/temp<<endl;
    system("pause");
    return 0;
}