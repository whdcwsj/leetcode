#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>score(n);
    for(int i=0;i<n;i++){
        cin>>score[i];
    }
    if(x>n/2) cout<<-1<<endl;
    if(y<n/2+n%2) cout<<-1<<endl;
    sort(score.begin(),score.end());
    // x<m<y && x<n-m<y
    // m是分数位次,m>n-y,m>x,m得满足的条件
    int less=max(n-y,x);
    int res=score[less-1];
    //找意外情况,1,2,2,2,3,4
    int i;
    for(i=less;i<n;i++){
        if(score[i]!=res){
            break;
        }
    }
    if(n-i>=x&& n-i<=y&&i>=x&& i<=y){
        cout<<res<<endl;;
    }else{
        cout<<-1<<endl;
    }

    system("pause");
    return 0;
}