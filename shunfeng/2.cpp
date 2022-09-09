#include<bits/stdc++.h>
using namespace std;


// int main(){
//     int n;
//     cin>>n;
//     if(n==1){
//         cout<<1<<endl;
//         return 0;
//     }
//     int dp[n+1][n+1];
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=n;j++){
//             dp[i][j]=0;
//         }
//     }
//     //初始化数值
//     for(int i=0;i<=n;i++){
//         dp[i][i]=0;
//     }
//     for(int j=2;j<=n;j++){
//         for(int i=j-1;i>=1;i--){
//             //除了两端外的分割点
//             for(int k=i+1;k<=j-1;k++){
//                 dp[i][j]=max(dp[i][j],1+max(dp[i][k-1],dp[k+1][j]));
//             }
//             //两端
//             dp[i][j]=max(dp[i][j],1+dp[i+1][j]);
//             dp[i][j]=max(dp[i][j],1+dp[i][j-1]);
//         }
//     }
//     cout<<dp[1][n]<<endl;


//     system("pause");
//     return 0;
// }


int main(){
    int n;
    cin>>n;

    long long res=0;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=1;i<=n-1;i++){
        res+=i;
    }
    if(n%2==0){
        cout<<res<<endl;
    }else{
        cout<<res+1<<endl;
    }
   


    system("pause");
    return 0;
}