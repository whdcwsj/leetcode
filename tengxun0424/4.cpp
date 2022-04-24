#include<bits/stdc++.h>
using namespace std;

int lowbit(int x){
    return x&(-x);
}

void update(vector<int>&tree,int n,int i,int k){
    while(i<=n){
        tree[i]+=k;
        i+=lowbit(i);
    }
}

int getSum(vector<int>&tree,int i){
    int res=0;
    while(i>0){
        res+=tree[i];
        i-=lowbit(i);
    }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    unordered_map<int,int>um;
    vector<int>nums;
    int tmp;
    for(int i=0;i<n;i++){
        cin>>tmp;
        um[tmp]=1;
        nums.push_back(tmp);
    }
    for(int i=0;i<m;i++){
        cin>>tmp;
        um[tmp]=-1;
        nums.push_back(tmp);
    }
    sort(nums.begin(),nums.end());
    n=nums.size();
    vector<int>tree(n+1,0);
    for(int i=0;i<n;i++){
        update(tree,n,i+1,um[nums[i]]);
    }
    int q;
    cin>>q;
    vector<int>ans(3,0);
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int ll=lower_bound(nums.begin(),nums.end(),l)-nums.begin();
        int rr=lower_bound(nums.begin(),nums.end(),r)-nums.begin();
        int t=getSum(tree,rr+1)-getSum(tree,ll);
        if(t>0){
            ans[0]++;
        }else if(t<0){
            ans[2]++;
        }else{
            ans[1]++;
        }
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;

    system("pause");
    return 0;
}