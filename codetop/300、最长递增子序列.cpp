#include<bits/stdc++.h>
using namespace std;


//保持严格递增的子序列
int lengthOfLIS(vector<int>& nums){
    int n=nums.size();
    if(n==1) return 1;
    //递增子序列，初始的时候都为1
    int res=1;
    vector<int>dp(n,1);
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
        if(dp[i]>res) res=dp[i];
    }
    return res;
}

int main(){
    //vector<int>nums={10,9,2,5,3,7,101,18};
    vector<int>nums={-1,-2,-3,-4,-5,-6};
    int res=lengthOfLIS(nums);
    cout<<res<<endl;

    system("pause");
    return 0;
}