#include<bits/stdc++.h>
using namespace std;

int ans=0;

bool cmp(string&a,string&b,int index){
    for(int i=0;i<b.length();i++){
        if(b[i]!=a[index+i]){
            return false;
        }
    }
    return true;
}

void dfs(string&total,vector<int>&visited,vector<string>&w,int p){
    if(p==total.size()){
        ans++;
        return;
    }
    for(int i=0;i<w.size();i++){
        if(visited[i]==0 && cmp(total,w[i],p)){
            visited[i]=1;
            dfs(total, visited, w, p+w[i].size());
            visited[i]=0;
        }
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    string total;
    cin>>total;
    vector<int>l(m,0);
    vector<string>w(m,"");
    for(int i=0;i<m;i++){
        cin>>l[m];
    }
    for(int i=0;i<m;i++){
        string temp;
        cin>>temp;
        w[i]=temp;
    }
    vector<int>visited(m,0);
    dfs(total,visited,w,0);
    cout<<ans<<endl;

    system("pause");
    return 0;
}