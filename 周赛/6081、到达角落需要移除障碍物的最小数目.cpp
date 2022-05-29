#include<bits/stdc++.h>
using namespace std;


//返回障碍物的最小数量
//把障碍物当作可以经过的单元格，经过它的代价为1，空单元格经过的代价为0
//于是通过堆来排序的思路可以换作双端队列来手动排序，+0的排到队头，+1的排到队尾

//直接BFS会超时
//时间复杂度: O(n)

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int minimumObstacles(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<bool>>visited(n,vector<bool>(m));
    vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
    dis[0][0]=0;
    //双端队列
    deque<pair<int,int>>dp;
    dp.push_back({0,0});
    while(!dp.empty()){
        auto [x,y]=dp.front();
        dp.pop_front();
        for(int k=0;k<4;k++){
            int new_x=x+dx[k];
            int new_y=y+dy[k];
            if(new_x<0 || new_x>=n || new_y<0 || new_y>=m || visited[new_x][new_y]){
                continue;
            }
            visited[new_x][new_y]=true;
            dis[new_x][new_y]=dis[x][y]+grid[new_x][new_y];
            //有陷阱，放在队尾，空格，放在对头
            if(grid[new_x][new_y]){
                dp.push_back({new_x,new_y});
            }else{
                dp.push_front({new_x,new_y});
            }
        }
    }
    return dis[n-1][m-1];
}


int main(){
    vector<vector<int>>grid = {{0,1,1},{1,1,0},{1,1,0}};
    int ans=minimumObstacles(grid);
    cout<<ans<<endl;

    system("pause");
    return 0;
}