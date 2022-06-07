#include<bits/stdc++.h>
using namespace std;


vector<int> printNumbers(int n) {
    vector<int>res;
    int maxnum=1;
    while(n--){
        maxnum*=10;
    }
    for(int i=1;i<maxnum;i++){
        res.push_back(i);
    }
    return res;
}


int main(){
    int n=1;
    vector<int>res=printNumbers(n);
    for(auto &a:res){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}