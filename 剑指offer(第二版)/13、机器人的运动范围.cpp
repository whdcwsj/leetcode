#include<bits/stdc++.h>
using namespace std;


int digitNum(int num){
    int res=0;
    while(num>0){
        res+=num%10;
        num=num/10;
    }
    return res;
}

vector<vector<bool>>visited;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int fangge=0;
int row;
int col;

void dfs(vector<vector<bool>>&visited,int x,int y,int k){
    visited[x][y]=1;
    fangge++;
    for(int i=0;i<4;i++){
        auto newx=x+dx[i];
        auto newy=y+dy[i];
        if(newx>=0 && newx<row && newy>=0 && newy<col && !visited[newx][newy] && digitNum(newx)+digitNum(newy)-k<=0){
            dfs(visited,newx,newy,k);
        }
    }
}


int movingCount(int m, int n, int k) {
    if(k==0) return 1;
    row=m;
    col=n;
    visited.resize(m,vector<bool>(n));
    dfs(visited,0,0,k);
    return fangge;
}


int main(){
    int m = 2, n = 3, k = 1;
    int ans=movingCount(m,n,k);
    cout<<ans<<endl;

    system("pause");
    return 0;
}