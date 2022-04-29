#include<bits/stdc++.h>
using namespace std;

int t;
vector<int>nums;

int main(){
    cin>>t;
    nums.resize(t);
    for(int i=0;i<t;i++){
        cin>>nums[i];
    }
    //cout<<"111"<<endl;
    int n=max_element(nums.begin(),nums.end())-nums.begin();
    int w=nums[n];
    vector<vector<int>>dp(w+4,vector<int>(2,0));
    dp[0][0]=1;
    dp[0][1]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    int i;
    for(i=2;i<w;i+=4){
        dp[i+2][0]=1;
        dp[i+3][0]=1;
    }
    for(int i=2;i<w;i++){
        dp[i][1]=(i+1)-dp[i-1][0];
    }
    //cout<<"wang"<<endl;
    for(int i=0;i<t;i++){
        cout<<dp[nums[i]-1][0]<<" "<<dp[nums[i]-1][1]<<endl;
    }
    system("pause");
    return 0;
}