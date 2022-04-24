#include<iostream>
using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        if(a<1 || b>1000){
            cout<<"false"<<endl;
        }else{
            cout<<a+b<<endl;
        }
    }
    return 0;
}