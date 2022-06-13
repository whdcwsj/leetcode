#include<bits/stdc++.h>
using namespace std;



//要寻找最小的不公平程度
//不公平程度:定义为单个孩子在分发过程中能够获得饼干的最大总数。
//回溯

int res=INT_MAX;
void dfs(const vector<int>&cookies,int cur,int k,vector<int>&sum,int opt){
    int n=cookies.size();
    if(n==cur){
        res=min(res,opt);
        return;
    }
    for(int i=0;i<k;i++){
        sum[i]+=cookies[cur];
        dfs(cookies,cur+1,k,sum,max(opt,sum[i]));
        sum[i]-=cookies[cur];
    }
}


int distributeCookies(vector<int>& cookies, int k) {
    vector<int>sum(k,0);
    dfs(cookies,0,k,sum,0);
    return res;
}


//a<<b的值实际上就是a乘以2的b次方
int main(){
    vector<int>cookies = {8,15,10,20,8};
    int k = 2;
    int ans=distributeCookies(cookies,k);
    cout<<ans<<endl;
\
    

    system("pause");
    return 0;
}