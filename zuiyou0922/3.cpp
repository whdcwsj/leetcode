#include<bits/stdc++.h>
using namespace std;


int main(){
    int n,m;
    cin>>n>>m;
    double res=0.0;
    if(m<n || m>n*6){
        cout<<fixed<<setprecision(6)<<res<<endl;
        return 0;
    }
    //不断更换dp就行
    vector<double>dp(6,1.0/6.0);
    for(int i=2;i<=n;i++){
        vector<double>temp(5*i+1,0);
        for(int j=0;j<dp.size();j++){
            for(int k=0;k<6;k++){
                temp[j+k]+=dp[j]/6.0;
            }
        }
        dp=temp;
    }
    cout<<fixed<<setprecision(6)<<dp[m-n]<<endl;

    system("pause");
    return 0;
}