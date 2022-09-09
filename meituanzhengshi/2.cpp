#include<bits/stdc++.h>
using namespace std;

int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    string instruction;
    cin>>instruction;
    int total=n*m-1;
    vector<vector<int>>visited(n,vector<int>(m,0));
    visited[0][0]=1;
    string flag;
    int cur_ins=-1;
    
    int x=0;
    int y=0;
    for(int i=0;i<k;i++){
        if(instruction[i]=='W'){
            x+=dx[0];
            y+=dy[0];
            if(y<0){
                flag="No";
                break;
            }
        }else if(instruction[i]=='S'){
            x+=dx[1];
            y+=dy[1];
            if(y>=n){
                flag="No";
                break;
            }
        }else if(instruction[i]=='A'){
            x+=dx[2];
            y+=dy[2];
            if(x<0){
                flag="No";
                break;
            }
        }else if(instruction[i]=='D'){
            x+=dx[3];
            y+=dy[3];
            if(x>=m){
                flag="No";
                break;
            }
        }

        if(visited[x][y]==0){
            visited[x][y]=1;
            total--;
        }

        if(total==0){
            flag="Yes";
            cur_ins=i;
            break;
        }
    }

    //所有指令执行完，还有未打扫的
    if(total>0){
        flag="No";
    }

    if(flag=="Yes"){
        cout<<flag<<endl;
        cout<<cur_ins+1<<endl;
    }else if(flag=="No"){
        cout<<flag<<endl;
        cout<<total<<endl;
    }

    system("pause");
    return 0;
}