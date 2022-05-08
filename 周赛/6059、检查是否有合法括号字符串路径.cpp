#include<bits/stdc++.h>
using namespace std;


//以dp数组来记录到每一步是否合法
//左括号+1，右括号-1
//记f(i,j,k)表示是否存在以格子(i,j)为结尾，且now值是k的括号序列
//维护一个变量k记录数值
bool hasValidPath(vector<vector<char>>& grid) {
        if (grid[0][0] == ')') return false;

        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<bool>>> f;
        for (int i = 0; i < n; i++) {
            f.push_back(vector<vector<bool>>());
            for (int j = 0; j < m; j++) f.back().push_back(vector<bool>(n + m));
        }
        f[0][0][1] = true;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (i || j) {
            int t = (grid[i][j] == '(' ? 1 : -1);
            for (int k = 0; k < n + m; k++) {
                int kk = k - t;
                if (kk < 0 || kk >= n + m) continue;
                if (i) f[i][j][k] = f[i][j][k] || f[i - 1][j][kk];
                if (j) f[i][j][k] = f[i][j][k] || f[i][j - 1][kk];
            }
        }
        return f[n - 1][m - 1][0];
}


int main(){
    vector<vector<char>>grid = {{'(','(','('},{')','(',')'},{'(','(',')'},{'(','(',')'}};
    bool ans=hasValidPath(grid);
    cout<<ans<<endl;

    system("pause");
    return 0;
}