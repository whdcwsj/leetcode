#include<bits/stdc++.h>
using namespace std;


//很多board中有很多a的情况下，string也有很多a，会超时
// int dx[4]={-1,1,0,0};
// int dy[4]={0,0,-1,1};
// bool flag;

// void dfs(vector<vector<char>>& board,string &word,int x,int y,int &count,vector<vector<bool>>&visited){
//     int m=board.size();
//     int n=board[0].size();
//     for(int i=0;i<4;i++){
//         auto newx=dx[i]+x;
//         auto newy=dy[i]+y;
//         if(newx<0 || newx>=m || newy<0 || newy>=n || visited[newx][newy]==1){
//             continue;
//         }
//         if(board[newx][newy]==word[count]){
//             count++;
//             //找到一个满足条件的就行，后续不用遍历
//             if(count==word.size()){
//                 flag=true;
//                 break;
//             }
//             visited[newx][newy]=1;
//             dfs(board,word,newx,newy,count,visited);
//             //注意回溯
//             visited[newx][newy]=0;
//             count--;
//         }
//     }
// }

// bool exist(vector<vector<char>>& board, string word) {
//     vector<vector<bool>>visited;
//     int row=board.size();
//     int col=board[0].size();
//     int count;
//     flag=false;
//     for(int i=0;i<row;i++){
//         for(int j=0;j<col;j++){
//             if(board[i][j]==word[0]){
//                 count=1;
//                 if(word.size()==count){
//                     flag=true;
//                 }
//                 visited.clear();
//                 visited.resize(row,vector<bool>(col,0));
//                 visited[i][j]=1;
//                 dfs(board,word,i,j,count,visited);
//                 if(flag==true){
//                     break;
//                 }
//             }
//         }
//         if(flag==true) break;
//     }
//     return flag;
// }


//为了避免超时，要精简一下
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int row;
int col;

bool dfs(vector<vector<char>>& board,string &word,int x,int y,int index,vector<vector<bool>>&visited){
    if(index==word.size()-1){
        if(board[x][y]==word[index]){
            return true;
        }
    }
    if(board[x][y]==word[index]){
        index++;
        visited[x][y]=true;
        for(int i=0;i<4;i++){
            auto newx=dx[i]+x;
            auto newy=dy[i]+y;
            if(newx>=0 && newx<row && newy>=0 && newy<col && visited[newx][newy]==0){
                if(dfs(board,word,newx,newy,index,visited)){
                    return true;
                }
            }
        }
        //回溯
        index--;
        visited[x][y]=false;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word){
    row=board.size();
    col=board[0].size();
    vector<vector<bool>>visited;
    visited.resize(row,vector<bool>(n));
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(dfs(board,word,i,j,0,visited)){
                return true;
            }
        }
    }
    return false;
}







int main(){
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="ABCCED";
    // vector<vector<char>> board = {{'C','A','A'},{'A','A','A'},{'B','C','D'}};
    // string word="AAB";
    bool ans=exist(board,word);
    cout<<ans<<endl;

    system("pause");
    return 0;
}