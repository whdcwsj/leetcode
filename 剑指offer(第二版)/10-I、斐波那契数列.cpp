#include<bits/stdc++.h>
using namespace std;


//1、这样时间复杂度，空间复杂度都是O(n)
int fib(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    long long k=1e9+7;
    vector<long long>dp(n+1);
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=(dp[i-2]+dp[i-1])%k;
    }
    return dp[n];
}

//2、使用滑动数组，优化空间复杂度为O(1)，时间复杂度还是O(n)
int fib(int n) {
    if(n<2) return n;
    long long k=1e9+7;
    long long p=0;
    long long q=0;
    long long r=1;
    for(int i=2;i<=n;i++){
        p=q;
        q=r;
        r=(p+q)%k;
    }
    return r;
}

//3、矩阵快速幂，可以进一步优化时间复杂福为O(log n)，空间复杂度O(1)


int main(){
    int n=45;
    int res=fib(n);
    cout<<res<<endl;

    system("pause");
    return 0;
}
