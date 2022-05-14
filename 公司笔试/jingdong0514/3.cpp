#include<bits/stdc++.h>
using namespace std;

//记录边
vector<vector<int>>edges;
//记录度数(入度+出度)
vector<int>deg;
stack<int>s;
vector<int>res;

int main(){
    //六个节点
    int n=6;
    edges.resize(n+1,vector<int>(n+1));
    deg.resize(n+1);
    edges[1][2]=1;
    edges[2][1]=1;
    deg[1]++;
    deg[2]++;
    edges[2].push_back(3);
    edges[2][3]=1;
    edges[3][2]=1;
    deg[2]++;
    deg[3]++;
    edges[1].push_back(4);
    edges[1][4]=1;
    edges[4][1]=1;
    deg[1]++;
    deg[4]++;
    edges[3].push_back(5);
    edges[3][5]=1;
    edges[5][3]=1;
    deg[3]++;
    deg[5]++;
    edges[3].push_back(6);
    edges[3][6]=1;
    edges[6][3]=1;
    deg[3]++;
    deg[6]++;

    for(int i=1;i<=n;i++){
        if(deg[i]==1){
            s.push(i);
        }
    }
    while(!s.empty()){
        int temp=s.top();
        s.pop();
        res.push_back(temp);
        deg[temp]--;
        for(int i=1;i<=n;i++){
            if(edges[temp][i]==1){
                deg[i]--;
                if(deg[i]==1){
                    s.push(i);
                }
            }
        }
    }
    int leng=res.size();
    for(int i=0;i<leng;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}