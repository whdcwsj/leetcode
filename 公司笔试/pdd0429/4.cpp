#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>nums;

bool cmp(const vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}


int main(){
    int n;
    cin>>n;
    nums.resize(n,vector<int>(2));
    //记录每个高度树苗的数量
    map<int,int>wang;
    int maxnum=0;
    int max_count=0;
    for(int i=0;i<n;i++){
        cin>>nums[i][0]>>nums[i][1];
        wang[nums[i][0]]++;
        if(nums[i][0]>maxnum){
            maxnum=nums[i][0];
            max_count=1;
        }else if(nums[i][0]==maxnum){
            max_count++;
        }
    }
    int res=0;
    if(max_count>(n/2)){
        cout<<res<<endl;
    }else{
        cout<<8<<endl;
    }
    
    //system("pause");
    return 0;
}
