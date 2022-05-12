#include<bits/stdc++.h>
using namespace std;


//1、dp做法
int minimumDeletions(string s) {
    int n=s.size();
    vector<int>dp(n+1);
    int count_b=0;
    for(int i=1;i<=n;i++){
        if(s[i-1]=='b'){
            dp[i]=dp[i-1];
            count_b++;
        }else{
            dp[i]=min(dp[i-1]+1,count_b);
        }
    }
    return dp[n];
}



//2、前缀和+后缀数组
//后缀统计当前索引及后续索引累计B出现的次数
//前缀统计不包含自身左侧A出现的次数
int minimumDeletions(string s){
    int n=s.size();
    vector<int>right(n+1);
    for(int i=n-1;i>=0;i--){
        right[i]=right[i+1];
        if(s[i]=='b'){
            right[i]++;
        }
    }
    int maxLen=0;
    int left=0;
    for(int i=0;i<n;i++){
        maxLen=max(maxLen,left+right[i]);
        if(s[i]=='a'){
            left++;
        }
    }
    //最后一次循环被漏掉，补上
    maxLen=max(maxLen,left);
    return n-maxLen;
}



int main(){
    string s = "aababbab";
    int ans=minimumDeletions(s);
    cout<<ans<<endl;

    system("pause");
    return 0;
}