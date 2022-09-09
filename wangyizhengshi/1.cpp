#include<bits/stdc++.h>
using namespace std;

static bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    return a.first>a.second;
}


int main(){
    int n;
    cin>>n;
    vector<int>nums(n,0);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<pair<int,int>>record;
    for(int i=0;i<n;i++){
        record.push_back(make_pair(nums[i],i));
    }
    sort(record.begin(),record.end(),cmp);
    int res=0;
    if(n==1) cout<<res<<endl;
    vector<pair<int,int>>wang;
    int left=0;
    int right=n-1;
    while(left<right){
        auto big=record[left];
        auto small=record[right];
        while(big.second<small.second){
            res++;
            
        }
    }

    



    system("pause");
    return 0;
}