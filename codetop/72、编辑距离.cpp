#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2){
    //dp[i][j]:w1的i位置转换到w2的j位置所需的最小次数
    int m=word1.size();
    int n=word2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    //初始化
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(word1[i-1]==word2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]})+1;
            }
        }
    }
    return dp[m][n];
}


int main(){
    string w1="horse",w2="ros";
    int res=minDistance(w1,w2);

    cout<<res<<endl;

    system("pause");
    return 0;
}