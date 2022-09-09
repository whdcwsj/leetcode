#include<bits/stdc++.h>
using namespace std;


long long dx[4]={0,0,1,-1};
long long dy[4]={1,-1,0,0};

set<pair<long long,long long>>store1;
set<pair<long long,long long>>store2;
vector<pair<long long,long long>>store3;

void dfs1(long long cur_x,long long cur_y, vector<vector<long long>>&visited, long long&dis){
    if(cur_x-1<0 || cur_x-1==visited.size() || cur_y-1<0 || cur_y-1==visited.size() || visited[cur_x-1][cur_y-1]==1 || dis<0){
        return;
    }
    store1.insert(make_pair(cur_x,cur_y));
    visited[cur_x-1][cur_y-1]=1;
    for(int i=0;i<4;i++){
        long long new_x=cur_x+dx[i];
        long long new_y=cur_y+dy[i];
        dis--;
        dfs1(new_x,new_y,visited,dis);
        dis++;
    }
}

void dfs2(long long cur_x,long long cur_y, vector<vector<long long>>&visited, long long dis){
    if(cur_x-1<0 || cur_x-1==visited.size() || cur_y-1<0 || cur_y-1==visited.size() || visited[cur_x-1][cur_y-1]==1 || dis<0){
        return;
    }
    if(store1.find(make_pair(cur_x,cur_y))!=store1.end()){
        store2.insert(make_pair(cur_x,cur_y));
        // cout<<cur_x<<" "<<cur_y<<endl;
    }
    visited[cur_x-1][cur_y-1]=1;
    for(int i=0;i<4;i++){
        long long new_x=cur_x+dx[i];
        long long new_y=cur_y+dy[i];
        dis--;
        dfs2(new_x,new_y,visited,dis);
        dis++;
    }
}

void dfs3(long long cur_x,long long cur_y, vector<vector<long long>>&visited, long long dis){
    if(cur_x-1<0 || cur_x-1==visited.size() || cur_y-1<0 || cur_y-1==visited.size() || visited[cur_x-1][cur_y-1]==1 || dis<0){
        return;
    }
    if(store2.find(make_pair(cur_x,cur_y))!=store1.end()){
        store3.push_back(make_pair(cur_x,cur_y));
        // cout<<cur_x<<" "<<cur_y<<endl;
    }
    visited[cur_x-1][cur_y-1]=1;
    for(int i=0;i<4;i++){
        long long new_x=cur_x+dx[i];
        long long new_y=cur_y+dy[i];
        dis--;
        dfs3(new_x,new_y,visited,dis);
        dis++;
    }
}

static bool cmp(const pair<long long,long long>&a,const pair<long long,long long>&b){
    if(a.first!=b.first){
        return a.first<b.first;
    }else{
        return a.second<b.second;
    }
}


int main(){
    int n;
    cin>>n;
    vector<vector<long long>>graph1(n,vector<long long>(n,0));
    vector<vector<long long>>graph2(n,vector<long long>(n,0));
    vector<vector<long long>>graph3(n,vector<long long>(n,0));
    long long x1,y1,x2,y2,x3,y3;
    cin>>x1>>y1;
    // graph[x1-1][y1-1]=2;
    cin>>x2>>y2;
    // graph[x2-1][y2-1]=2;
    cin>>x3>>y3;
    // graph[x3-1][y3-1]=2;
    long long d1,d2,d3;
    cin>>d1>>d2>>d3;

    dfs1(x1,y1,graph1,d1);
    dfs2(x2,y2,graph2,d2);
    dfs3(x3,y3,graph3,d3);

    sort(store3.begin(),store3.end(),cmp);
    cout<<store3[0].first<<" "<<store3[0].second<<endl;

    system("pause");
    return 0;
}