#include<bits/stdc++.h>
using namespace std;

static bool cmp(const vector<int>&a,const vector<int>&b){
    if(a[0]!=b[0]){
        return a[0]<b[0];
    }else{
        return a[1]<b[1];
    }
    
}

int main(){
    int n,m;
    cin>>n>>m;
    if(m==0){
        cout<<0<<endl;
        return 0;
    }
    if(n==1 && m==1){
        cout<<0<<endl;
        return 0;
    }
    if(n==1 && m>1){
        cout<<1<<endl;
        return 0;
    }
    vector<vector<int>>points(m,vector<int>(2));
    int num;
    for(int i=0;i<m;i++){
        cin>>num;
        points[i][0]=num;
    }
    for(int i=0;i<m;i++){
        cin>>num;
        points[i][1]=num;
    }
    sort(points.begin(),points.end(),cmp);
    //记录商品情况
    vector<int>shop(n,0);
    //记录最右边的覆盖范围
    vector<int>cover(m,0);
    cover[0]=points[0][1];
    for(int i=1;i<m;i++){
        int left=points[i][0];
        if(left<=cover[i-1]){
            int right=min(points[i][1],cover[i-1]);
            for(int j=left;j<=right;j++){
                shop[j]=1;
            }
            cover[i]=max(cover[i-1],points[i][1]);
        }else{
            cover[i]=points[i][1];
        }
    }
    int res=0;
    for(int i=0;i<n;i++){
        if(shop[i]==1){
            res++;
        }
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}