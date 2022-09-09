#include<bits/stdc++.h>
using namespace std;


int qiuhe(int start,int end, vector<int>nums){
    int res=0;
    for(int i=start;i<end;i++){
        res+=abs(nums[i]);
    }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>nums1(n,0);
    vector<int>nums2(m,0);
    for(int i=0;i<n;i++){
        cin>>nums1[i];
    }
    for(int i=0;i<m;i++){
        cin>>nums2[i];
    }
    
    //dp[i][j]，数组nums1前i个,数组nums2前j个，相同花费的时间
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        dp[i][0]=qiuhe(0,i,nums1);
        // dp[i][0] = dp[i-1][0] + nums1[i-1];
    }
    for(int j=0;j<=m;j++){
        dp[0][j]=qiuhe(0,j,nums2);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(nums1[i-1]==nums2[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{
                dp[i][j]=min(min(dp[i-1][j]+abs(nums1[i-1]),dp[i][j-1]+abs(nums2[j-1])),dp[i-1][j-1]+abs(nums1[i-1]-nums2[j-1]));
            }
        }
    }
    cout<<dp[n][m]<<endl;


    system("pause");
    return 0;
}