#include<bits/stdc++.h>
using namespace std;


int count(vector<vector<int>>&part){
    int num=0;
    int x=part.size();
    int y=part[0].size();
    vector<vector<int>>dp(x,vector<int>(y,0));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(part[i][j]==1){
                if(dp[i][j]==0){
                    dp[i][j]=1;
                    num++;
                }
            }
        }
    }
}



int main(){
    int n,m;
    cin>>n>>m;
    string s;
    //1是陆地，0是海洋
    vector<vector<int>>graph(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='*'){
                graph[i][j]=1;
            }
        }
    }
    if(n==1 && m==1 && graph[0][0]==1){
        cout<<1<<endl;
        return 0;
    }
    if(n==1 && m==1 && graph[0][0]==0){
        cout<<0<<endl;
        return 0;
    }
    int res=0;
    int row1=n/2+n%2;
    int col1=m/2+m%2;
    vector<vector<int>>part1(row1,vector<int>(col1,0))
    for(int i=0;i<n;i+=2){
        for(int j=0;j<m;j+=2){
            if(graph[i][j]==1){
                part1[i/2][j/2]=1;
            }
        }
    }



    bool flag2=0;
    for(int i=0;i<n;i+=2){
        for(int j=1;j<m;j+=2){
            if(graph[i][j]==1){
                res++;
                flag2=1;
                break;
            }
        }
        if(flag2==1) break;
    }
    bool flag3=0;
    for(int i=1;i<n;i+=2){
        for(int j=0;j<m;j+=2){
            if(graph[i][j]==1){
                res++;
                flag3=1;
                break;
            }
        }
        if(flag3==1) break;
    }
    bool flag4=0;
    for(int i=1;i<n;i+=2){
        for(int j=1;j<m;j+=2){
            if(graph[i][j]==1){
                res++;
                flag4=1;
                break;
            }
        }
        if(flag4==1) break;
    }

    cout<<res<<endl;
    system("pause");
    return 0;
}