#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> position;

const int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void bfs(vector<vector<int>>&grid,int x,int y,int ex,int ey,vector<vector<int>>&dis){
    //终止条件
    if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size() || grid[x][y]==-1 || grid[x][y]==-1){
        return;
    }
    queue<position>q;
    q.push(position(x,y));
    dis[x][y]=0;
    int i;
    int index=4;
    while(!q.empty()){
        auto p=q.front();
        q.pop();
        for(i=0;i<4;i++){
            int new_x=p.first+dirs[i][0];
            int new_y=p.second+dirs[i][1];
            if(new_x>=0 && new_x<grid.size() && grid[new_x][new_y]==0 && dis[new_x][new_y]==-1){
                q.push(position(new_x,new_y));
                dis[new_x][new_y]=dis[p.first][p.second]+1;
            }
            //找到答案
            if(new_x==ex && new_y==ey){
                break;
            }
        }
        if(i!=index){
            break;
        }
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>>grid(m,vector<int>(n,-3));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    //初始化距离为-1，标记没访问过
    vector<vector<int>>dis(m,vector<int>(n,-1));
    int start_x,start_y;
    int end_x,end_y;
    cin>>start_x>>start_y>>end_x>>end_y;

    bfs(grid,start_x,start_y,end_x,end_y,dis);
    if(dis[end_x][end_y]==-1){
        cout<<-1<<endl;
        return 0;
    }
    cout<<dis[end_x][end_y]<<endl;

    system("pause");
    return 0;
}