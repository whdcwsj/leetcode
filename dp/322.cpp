#include<iostream>
using namespace std;


int main() {
        vector<int>conis={[1,2,5]};
        amount=11;
        //dp[i]，amount=i的最少硬币数目
        // 硬币数目不限制
        vector<int>dp(amount+1,0);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){
                dp[i]=min(dp[i],dp[j-coins[i]]+1);
            }
        }
        return 0;
    }