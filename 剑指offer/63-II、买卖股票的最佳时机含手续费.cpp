#include<bits/stdc++.h>
using namespace std;


//dp[i][0]不持有股票
//dp[i][1]持有股票
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    if(n==1) return 0;
    vector<vector<int>>dp(n,vector<int>(2,0));
    dp[0][0]=0;
    dp[0][1]=-prices[0];
    for(int i=1;i<n;i++){
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]-fee);
        dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);
    }
    return dp[n-1][0];
}



//贪心
//当卖出一支股票时，就立即获得了以相同价格并且免除手续费买入一支股票的权利
int maxProfit(vector<int>& prices, int fee) {
    int n=prices.size();
    if(n==1) return 0;
    int buy=prices[0]+fee;
    int res=0;
    for(int i=1;i<n;i++){
        //有更低的价格
        if(prices[i]+fee<buy){
            buy=prices[i]+fee;
        }
        else if(prices[i]>buy){
            res+=prices[i]-buy;
            buy=prices[i];
        }
    }
    return res;
}


int main(){
    vector<int> prices={1, 3, 2, 8, 4, 9};
    int fee=2;
    int ans=maxProfit(prices,fee);
    cout<<ans<<endl;

    system("pause");
    return 0;
}