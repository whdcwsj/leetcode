#include<bits/stdc++.h>
using namespace std;

//要注意，取模运算，不能dp计算啊
int cuttingRope(int n) {
    if(n<=3) return n-1;
    long long res=1;
    long long mod=1e9+7;
    while(n>4){
        n-=3;
        res=res*3%mod;
    }
    res=res*n%mod;
    return res;
}


int main(){
    int n=120;
    int ans=cuttingRope(n);
    cout<<ans<<endl;

    system("pause");
    return 0;
}