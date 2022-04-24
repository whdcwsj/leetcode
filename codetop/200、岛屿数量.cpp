#include<bits/stdc++.h>
using namespace std;


//这样超时了
// int dx[4]={-1,1,0,0};
// int dy[4]={0,0,1,-1};
// vector<vector<bool>>visited;
// int row,col;

// void bfs(int x,int y,vector<vector<string>>&grid){
//     queue<pair<int,int>>q;
//     q.push({x,y});
//     while(!q.empty()){
//         auto temp=q.front();
//         q.pop();
//         visited[temp.first][temp.second]=1;
//         for(int i=0;i<4;i++){
//             int newx=temp.first+dx[i];
//             int newy=temp.second+dy[i];
//             if(newx<0 || newx>=row ||newy<0 || newy>=col || visited[newx][newy] || grid[newx][newy]=="0"){
//                 continue;
//             }
//             q.push({newx,newy});
//         }
//     }
// }

// int numIslands(vector<vector<string>>& grid){
//     row=grid.size();
//     col=grid[0].size();
//     visited.resize(row,vector<bool>(col,0));
//     int res=0;
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             if(!visited[i][j] && grid[i][j]=="1"){
//                 bfs(i,j,grid);
//                 res++;
//             }
//         }
//     }
//     return res;
// }


// BFS解法：
// int dx[4]={-1,1,0,0};
// int dy[4]={0,0,1,-1};

// //去掉visited，直接在grid中间直接修改
// int numIslands(vector<vector<char>>& grid){
//     int m=grid.size();
//     int n=grad[0].size();
//     int res=0;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             if(grid[i][j]=='1'){
//                 res++;
//                 grid[i][j]='0';
//                 queue<pair<int,int>>q;
//                 q.push({i,j});
//                 while(!q.empty()){
//                     auto temp=q.front();
//                     q.pop();
//                     for(int k=0;k<4;k++){
//                         auto x=temp.first+dx[k];
//                         auto y=temp.second+dy[k];
//                         if(x<0 || x>=m ||y<0 || y>=n|| grid[x][y]=='0'){
//                             continue;
//                         }
//                         q.push({x,y});
//                         grid[x][y]='0';
//                     }
//                 }
//             }
//         }
//     }
//     return res;
// }


int dx[4]={-1,1,0,0};
int dy[4]={0,0,1,-1};

//DFS解法
void dfs(vector<vector<char>>&grid,int x,int y){
    int m=grid.size();
    int n=grid[0].size();
    grid[x][y]='0';
    for(int i=0;i<4;i++){
        auto newx=x+dx[i];
        auto newy=y+dy[i];
        if(newx<0 || newx>=m || newy<0 || newy>=n ||grid[newx][newy]=='0'){
            continue;
        }
        dfs(grid,newx,newy);
    }
}


int numIslands(vector<vector<char>>& grid){
    int m=grid.size();
    int n=grid[0].size();
    int res=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]=='1'){
                res++;
                dfs(grid,i,j);
            }
        }
    }
    return res;
}




int main(){
    // vector<vector<string>>grid = {
    //     {"1","1","1","1","0"},
    //     {"1","1","0","1","0"},
    //     {"1","1","0","0","0"},
    //     {"0","0","0","0","0"}
    // };

    vector<vector<string>>grid ={
    {"1","1","0","0","0"},
    {"1","1","0","0","0"},
    {"0","0","1","0","0"},
    {"0","0","0","1","1"}
    };

    int num=numIslands(grid);

    cout<<num<<endl;

    system("pause");
    return 0;
}