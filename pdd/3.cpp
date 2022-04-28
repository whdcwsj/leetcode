#include<bits/stdc++.h>
using namespace std;

int n,m;

//前缀和，同余
int main(){
    cin>>n>>m;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int>pre(n+1);
    unordered_map<int,int>wang={{0,1}};
    //注意这里，结果可能超出范围
    long res=0;
    for(int i=1;i<=n;i++){
        pre[i]=(pre[i-1]+(nums[i-1])%m)%m;
        if(wang.count(pre[i])){
            res+=wang[pre[i]];
        }
        wang[pre[i]]++;
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}