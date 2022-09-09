#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<int>nums;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        nums.push_back(temp);
    }
    vector<int>dp(100001,0);
    dp[1]=0;
    dp[2]=1;
    dp[3]=2;
    for(int i=4;i<=100000;i++){
        dp[i]=dp[i-1]+1;
        for(int j=int(sqrt(i));j>1;j--){
            if(i%j==0){
                dp[i]=dp[j]+dp[i/j]+1;
                break;
            }
        }
    }
    long long res=0;
    for(int i=0;i<n;i++){
        res+=dp[nums[i]];
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}