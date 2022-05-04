#include<bits/stdc++.h>
using namespace std;


int numWays(int n) {
    if(n==0) return 1;
    if(n==1 || n==2) return n;
    int mod=1e9+7;
    vector<int>dp(n+1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod;
    }
    return dp[n];
}

//滑动数组
int numWays(int n) {
    if(n==0) return 1;
    if(n==1 || n==2) return n;
    int mod=1e9+7;
    int a=1;
    int b=2;
    int sum=0;
    for(int i=3;i<=n;i++){
        sum=(a+b)%mod;
        a=b;
        b=sum;
    }
    return sum;
}


int main(){
    int n=7;
    int ans=numWays(n);
    cout<<ans<<endl;

    system("pause");
    return 0;
}