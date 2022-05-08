#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

//分组线性dp
//2,3,4,5,6，对应三个字母
//7,8,9，对应四个字母
int countTexts(string s) {
    int n=s.size();
    vector<int>dp(n+1);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        //一个字符的情况
        dp[i]=dp[i-1];
        //加上两个字符的情况
        if(i>=2 && s[i-1]==s[i-2]){
            dp[i]=(dp[i]+dp[i-2])%mod;
        }
        //加上三个字符的情况
        if(i>=3 && s[i-1]==s[i-2] && s[i-2]==s[i-3]){
            dp[i]=(dp[i]+dp[i-3])%mod;
        }
        //加上四个字符的情况
        if(i>=4 && s[i-1]==s[i-2] && s[i-2]==s[i-3] && s[i-3]==s[i-4] && (s[i-1]=='7' || s[i-1]=='9')){
            dp[i]=(dp[i]+dp[i-4])%mod;
        }
    }
    return dp[n];

}


int main(){
    string pressedKeys = "22233";
    int ans=countTexts(pressedKeys);
    cout<<ans<<endl;

    system("pause");
    return 0;
}