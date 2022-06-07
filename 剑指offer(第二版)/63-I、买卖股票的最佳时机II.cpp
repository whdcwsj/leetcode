#include<bits/stdc++.h>
using namespace std;


//可以买卖多次
int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(n==1) return 0;
    int res=0;
    for(int i=0;i<n-1;i++){
        res+=max(prices[i+1]-prices[i],0);
    }
    return res;
}


int main(){
    vector<int> prices={7,1,5,3,6,4};
    int ans=maxProfit(prices);
    cout<<ans<<endl;

    system("pause");
    return 0;
}