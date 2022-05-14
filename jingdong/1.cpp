#include<bits/stdc++.h>
using namespace std;
const int N 1e4+7;

vector<int>a;

//哨兵问题
// dp[i][j][0/1/2] 代表以a[i]为结尾，a[i]=j时的序列种数。
// 第三维代表a[i-1]和a[i]的大小关系(>, ==, <)。
long long dp[N][207][3];
long long preSum1[207], preSum2[207];


int main(){
    int mod=998244353;
    int n;
    cin>>n;
    a.resize(N);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //设置两端的哨兵，前两个条件可以排除
    a[0]=1;
    a[n+1]=1;
    //预处理
    dp[0][1][1]=1;
    for(int i=1;i<=200;i++){
        preSum1[i]=1;
        preSum2[i]=1;
    }
    for(int i=1;i<=n+1;i++){
        int l=1;
        int r=200;
        if(a[i]){
            l=r=a[i];
        }
        for(int j=l;j<=r;j++){
            dp[i][j][0]=(preSum2[200]-preSum2[j])%mod;
            dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%mod;
            dp[i][j][2]=preSum1[j-1]%mod;
        }
        // 更新前缀和
        for(int j=1;j<=200;j++) {
            preSum1[j] = preSum1[j - 1] + dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
            preSum2[j] = preSum2[j - 1] + dp[i][j][0] + dp[i][j][1];
        }
    }
    cout << (dp[n + 1][1][0]+dp[n + 1][1][1]) % mod << endl;

    system("pause");
    return 0;
}