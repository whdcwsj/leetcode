#include<bits/stdc++.h>
using namespace std;

vector<int>path;
//回溯,m个物品,n个选择，起始节点startindex
void backtracking(int n,int m,int startIndex){
    //终止条件
    if(path.size()==m){
        for(int i=0;i<m;i++){
            cout<<path[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=startIndex;i<=n;i++){
        //剪枝
        if(n-i+1<m-path.size()) break;
        path.push_back(i);
        backtracking(n,m,i+1);
        path.pop_back();
    }
}

int main(){
    int n,m;
    while(cin>>n>>m){
        backtracking(n,m,1);
    }
    return 0;
}