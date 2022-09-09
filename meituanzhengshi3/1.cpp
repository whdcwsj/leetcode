#include<bits/stdc++.h>
using namespace std;


bool compare(string p,string q){
    int n=q.size();
    bool flag=true;
    for(int i=0;i<n;i++){
        if(p[i]!=q[i] && q[i]!='*'){
            flag=false;
            break;
        }
    }
    return flag;
}

int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a;
    cin>>b;
    int res=0;
    if(n<m){
        cout<<res<<endl;
        return 0;
    }
    for(int i=0;i<=n-m;i++){
        if(compare(a.substr(i,m),b)){
            res++;
        }
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}
