#include<bits/stdc++.h>
using namespace std;

bool check(long long num){
    int res=0;
    bool flag=false;
    while(num){
        int temp=num%10;
        if(temp==5){
            res++;
            if(res==5){
                flag=true;
                break;
            }
        }
        num=num/10;
    }
    return flag;
}



int main(){
    long long n;
    cin>>n;
    n=n+1;
    long long res=0;
    for(n;;n++){
        if(check(n)){
            res=n;
            break;
        }
    }
    cout<<res<<endl;


    system("pause");
    return 0;
}