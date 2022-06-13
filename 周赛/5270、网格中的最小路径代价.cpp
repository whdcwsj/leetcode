#include<bits/stdc++.h>
using namespace std;


//鲜明的dp问题
//dp[i][j]表示到达grid[i][j]时的路径的的最小值
//要考虑单元格的数值
int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
    int m=grid.size();
    int n=grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
    //第一行的初始化
    for(int j=0;j<n;j++){
        dp[0][j]=grid[0][j];
    }
    for(int i=1;i<m;i++){
        for(int j=0;j<n;j++){
            //从dp[i-1][k]到dp[i][j]，需要再加一层循环，上一层的起点
            for(int k=0;k<n;k++){
                dp[i][j]=min(dp[i][j],dp[i-1][k]+moveCost[grid[i-1][k]][j]+grid[i][j]);
            }
        }
    }
    //返回的是迭代器，要加*
    return *min_element(dp[m-1].begin(),dp[m-1].end());
}



int main(){
    vector<vector<int>>grid = {{5,3},{4,0},{2,1}};
    vector<vector<int>> moveCost = {{9,8},{1,5},{10,12},{18,6},{2,4},{14,3}};
    int ans=minPathCost(grid,moveCost);
    cout<<ans<<endl;

    system("pause");
    return 0;
}