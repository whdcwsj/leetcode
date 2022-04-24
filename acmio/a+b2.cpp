#include<iostream>
using namespace std;

int main(){
    int a,b;
    int t;
    cin>>t;
    if(t<1){
        cout<<"false"<<endl;
    }else{
        while(t--){
            cin>>a>>b;
            if(a<1 || a>1000 || b<1 || b>1000){
                cout<<"false"<<endl;
            }else{
                cout<<a+b<<endl;
            }
        }
    }
    
    system("pause");
    return 0;
}