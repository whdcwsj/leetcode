#include<bits/stdc++.h>
using namespace std;


//动态规划
//1、点数dp
//dp(i,j):投完i枚骰子，点数j出现的次数
//dp[n][j]+=dp[n-1][j-i],i在1-6遍历

// vector<double> dicesProbability(int n) {
//     vector<vector<int>>dp(15,vector<int>(70,0));
//     for(int i=1;i<=6;i++){
//         dp[1][i]=1;
//     }
//     for(int i=2;i<=n;i++){
//         //当前骰子的点数范围
//         for(int j=i;j<=6*i;j++){
//             for(int cur=1;cur<=6;cur++){
//                 if(j-cur<=0) break;
//                 dp[i][j]+=dp[i-1][j-cur];
//             }
//         }
//     }
//     int all=pow(6,n);
//     vector<double>res;
//     for(int i=n;i<=6*n;i++){
//         res.push_back(dp[n][i]*1.0/all);
//     }
//     return res;
// }


//2、概率dp
vector<double> dicesProbability(int n) {
    vector<double>dp(6,1.0/6.0);
    for(int i=2;i<=n;i++){
        //和的范围，1-6，2-12，3-18
        vector<double>temp(5*i+1,0);
        //从前往后推进
        for(int j=0;j<dp.size();j++){
            for(int k=0;k<6;k++){
                temp[j+k]+=dp[j]/6.0;
            }
        }
        dp=temp;
    }
    return dp;
}



int main(){
    int n=2;
    vector<double>ans=dicesProbability(n);
    for(auto&a:ans){
        cout<<a<<" ";
    }
    cout<<endl;
    
    system("pause");
    return 0;
}