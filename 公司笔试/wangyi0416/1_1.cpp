#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<bool>>graph;
vector<vector<bool>>visited;
int dx[4]={-2,0,2,0};
int dy[4]={0,2,0,-2};

void bfs(int x,int y){
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        auto temp=q.front();
        q.pop();
        visited[temp.first][temp.second]=1;
        for(int i=0;i<4;i++){
            auto newx=dx[i]+temp.first;
            auto newy=dy[i]+temp.second;
            if(newx<0  || newx>=n || newy<0 || newy>=m || visited[newx][newy] || graph[newx][newy]==0){
                continue;
            }
            q.push({newx,newy});
        }
    }
}

int main(){
    cin>>n>>m;
    graph.resize(n,vector<bool>(m));
    visited.resize(n,vector<bool>(m));
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='*'){
                graph[i][j]=1;
            }
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] && !visited[i][j]){
                bfs(i,j);
                res++;
            }
        }
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}

// void bfs(int x, int y) {
//     queue<vector<int>> q;
//     q.push({x, y});
//     while (!q.empty()) {
//         auto p = q.front();
//         q.pop();
//         for (int i = 0; i < 4; ++i) {
//             auto newx = p[0] + dx[i];
//             auto newy = p[1] + dy[i];
//             if (newx < 0 || newy < 0 || newx >= n || newy >= m || visited[newx][newy] || !mdata[newx][newy])
//                 continue;
//             q.push({newx, newy});
//         }
//         visited[p[0]][p[1]] = true;
//     }
// }
