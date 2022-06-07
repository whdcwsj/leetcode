#include<bits/stdc++.h>
using namespace std;


int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums.front();
    vector<int>dp(n);
    dp[0]=nums[0];
    int maxNum=dp[0];
    for(int i=1;i<n;i++){
        if(dp[i-1]<=0) dp[i]=nums[i];
        else dp[i]=dp[i-1]+nums[i];
        maxNum=max(maxNum,dp[i]);
        cout<<maxNum<<endl;
    }
    return maxNum;
}



int main(){
    //vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums = {-1,-2};
    int ans=maxSubArray(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}