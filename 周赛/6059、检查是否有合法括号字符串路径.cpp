#include<bits/stdc++.h>
using namespace std;


//难点在于，到每个位置的时候，可能有2个得分信息,即是否可能的选项，因为有两条路径

//以dp数组来记录到每一步是否合法
//左括号+1，右括号-1
//记f(i,j,k)表示是否存在以格子(i,j)为结尾，且now值是k的括号序列
//维护一个变量k记录数值
bool hasValidPath(vector<vector<char>>& grid) {
        if(grid[0][0]==')') return false;
        int n=grid.size();
        int m=grid[0].size();
        //初始化，三维dp
        vector<vector<vector<bool>>>dp;
        for(int i=0;i<n;i++){
            dp.push_back(vector<vector<bool>>());
            for(int j=0;j<m;j++){
                dp.back().push_back(vector<bool>(n+m));
            }
        }
        dp[0][0][1]=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //排除[0,0]
                if(i!=0 || j!=0){
                    int temp=(grid[i][j]=='('?1:-1);
                    for(int k=0;k<n+m;k++){
                        //上一步的得分
                        int kk=k-temp;
                        if(kk<0 || kk>=n+m) continue;
                        //两个方向的行动路线
                        if(i>=1){
                            dp[i][j][k]=(dp[i][j][k] || dp[i-1][j][kk]);
                        }
                        if(j>=1){
                            dp[i][j][k]=(dp[i][j][k] || dp[i][j-1][kk]);
                        }
                    }
                }
            }
        }
        return dp[n-1][m-1][0];
    }


int main(){
    vector<vector<char>>grid = {{'(','(','('},{')','(',')'},{'(','(',')'},{'(','(',')'}};
    bool ans=hasValidPath(grid);
    cout<<ans<<endl;

    system("pause");
    return 0;
}