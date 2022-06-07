#include<bits/stdc++.h>
using namespace std;

//数学方法
//在短时间，思维不缜密的情况下不好写出来
// int cuttingRope(int n) {
//     if(n==2) return 1;
//     if(n==3) return 2;
//     if(n==4) return 4;
//     int res=1;
//     while(n>=3){
//         if(n==3 || n==4){
//             break;
//         }
//         n-=3;
//         res*=3;
//     }
//     res*=n;
//     return res;
// }


//动态规划
//dp[i]表示将长度为i的绳子剪成至少两段绳子之后，这些绳子长度的最大乘积
//当i≥2时，假设对长度为i绳子剪出的第一段绳子长度是j（1≤j<i）
//1、将i剪成j和i-j长度的绳子，且i−j不再继续剪，此时的乘积是 j×(i−j) ；
//2、将i剪成j和i−j长度的绳子，且i−j继续剪成多段长度的绳子，此时的乘积是j×dp[i−j] 。
//因此，当j固定时，有dp[i]=max(j×(i−j),j×dp[i−j])。
//由于j的取值范围是1到i需要遍历所有的j得到dp[i]

//可以进一步优化

int cuttingRope(int n){
    vector<int>dp(n+1);
    dp[2]=1;
    for(int i=3;i<=n;i++){
        for(int j=1;j<=i/2;j++){
            dp[i]=max(dp[i],max(j*(i-j),j*dp[i-j]));
        }
    }
    return dp[n];
}




int main(){
    int n=10;
    int ans=cuttingRope(n);
    cout<<ans<<endl;

    system("pause");
    return 0;
}