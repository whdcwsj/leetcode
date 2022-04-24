#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    int num=0;
    int res=0;
    while(cin>>n){
        if(n==0) return 0;
        res=0;
        num=n;
        while(num>=3){
            res+=num/3;
            num=num%3+num/3;
        }
        if(num==2) res++;
        cout<<res<<endl;
    }

    // system("pause");
    return 0;
}