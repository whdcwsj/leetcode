#include<bits/stdc++.h>
using namespace std;


//dp问题
int maxValue(vector<vector<int>>& grid) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
        }
    }
    return dp[m][n];
}


int main(){
    vector<vector<int>>grid={
        {1,3,1},
        {1,5,1},
        {4,2,1}
    };
    int ans=maxValue(grid);
    cout<<ans<<endl;

    system("pause");
    return 0;
}