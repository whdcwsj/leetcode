#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m,t;
    cin>>n>>m>>t;
    vector<int>time_a(n,0);
    vector<int>time_b(m,0);
    for(int i=0;i<n;i++){
        cin>>time_a[i];
    }
    for(int i=0;i<m;i++){
        cin>>time_b[i];
    }

    //前缀和
    vector<long long>presum_a(n+1,0);
    vector<long long>presum_b(m+1,0);
    presum_a[0]=0;
    for(int i=1;i<=n;i++){
        presum_a[i]=presum_a[i-1]+time_a[i-1];
    }
    presum_b[0]=0;
    for(int i=1;i<=m;i++){
        presum_b[i]=presum_b[i-1]+time_b[i-1];
    }

    int start=0;
    int end=m;
    int res=0;
    while(start<=n && end>=0){
        if(presum_a[start]+presum_b[end]<=t){
            res=max(res,start+end);
            start++;
        }else{
            end--;
        }
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}