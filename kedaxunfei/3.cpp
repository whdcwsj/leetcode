#include<bits/stdc++.h>
using namespace std;


int main(){
    int n=8;
    vector<vec>

    // BFS 
    vector<vector<int>>edges;
    vector<int>indeg;
    vector<int>res;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for(auto&a:prerequisites){
            edges[a[1]].push_back(a[0]);
            indeg[a[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            res.push_back(u);
            for(int v:edges[u]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        if(res.size()!=numCourses){
            return {};
        }
        return res;
    }
    

    system("pause");
    return 0;
}