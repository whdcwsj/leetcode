#include<bits/stdc++.h>
using namespace std;

/*
扔n个骰子，第i个骰子有可能投掷出Xi种等概率的不同的结果
数字从1到Xi。所有骰子的结果的最大值将作为最终结果。求最终结果的期望。
*/


int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    //记录最大数值
    int maxnum=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i]>maxnum){
            maxnum=nums[i];
        }
    }

    //概率计算公式
    //p(x=k)=p(x<=k)-p(x<=k-1)
    vector<double>res(maxnum+1);
    double s=0;
    for(int i=1;i<=maxnum;i++){
        double temp=1;
        for(int j=0;j<n;j++){
            temp*=(double)min(nums[j],i)/nums[j];
        }
        res[i]=temp;
        s+=(double)(res[i]-res[i-1])*i;
    }
    cout<<fixed<<setprecision(2)<<s<<endl;

    system("pause");
    return 0;
}