#include<bits/stdc++.h>
using namespace std;


//dp问题
int translateNum(int num) {
    string s=to_string(num);
    int n=s.size();
    if(n<=1) return n;
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]+=dp[i-1];
        if(s[i-2]=='1' || (s[i-2]=='2' && s[i-1]-'5'<=0)){
            dp[i]+=dp[i-2];
        }
    }
    return dp[n];
}


int main(){
    int num=12258;
    int ans=translateNum(num);
    cout<<ans<<endl;

    system("pause");
    return 0;
}