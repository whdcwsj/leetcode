#include<bits/stdc++.h>
using namespace std;


//复杂的字符串匹配，万事不决有dp
//注意，s或者p可能为空
bool isMatch(string s, string p) {
    int n=s.size()+1;
    int m=p.size()+1;
    vector<vector<bool>>dp(n,vector<bool>(m));
    //初始化
    //a*可以和null匹配，初始化dp[0][0]=1
    dp[0][0]=1;
    //第一行初始化
    for(int j=2;j<m;j++){
        if(p[j-1]=='*'){
            dp[0][j]=dp[0][j-2];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(j>=2 && p[j-1]=='*'){
                //看作零次，看作多一次(可能前面还有.)
                dp[i][j]= (dp[i][j-2] || (dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2]=='.')));
            }else if(p[j-1]!='*'){
                //s与p的当前字符相同，或者p的当前字符为.
                dp[i][j]= (dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.'));
            }
        }
    }
    return dp[n-1][m-1];
}


int main(){
    string s = "aab";
    string p = "c*a*b";
    bool ans=isMatch(s,p);
    cout<<ans<<endl;

    system("pause");
    return 0;
}