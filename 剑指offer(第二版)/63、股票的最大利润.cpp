#include<bits/stdc++.h>
using namespace std;



int maxProfit(vector<int>& prices) {
    int n=prices.size();
    if(n<=1) return 0;
    //当前最小值
    int cur=prices[0];
    int res=INT_MIN;
    for(int i=1;i<n;i++){
        cur=min(cur,prices[i]);
        res=max(res,prices[i]-cur);
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