#include<bits/stdc++.h>
using namespace std;

int sumOfFlooredPairs(vector<int>& nums) {
        long long mod=10e9+7;
        long long res=0;
        int n=nums.size();
        int maxnum=*max_element(nums.begin(),nums.end());
        vector<int>count(maxnum+1);
        //计数
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        //前缀和
        for(int i=1;i<=maxnum;i++){
            count[i]+=count[i-1];
        }
        //开始循环
        for(int i=1;i<=maxnum;i++){
            //当前分母的个数
            long x=count[i]-count[i-1];
            if(x==0) continue;
            for(int j=i;j<=maxnum;j+=i){
                //min()，避免i+j-1超出范围
                //当前分子的个数
                long y=count[min(maxnum,j+i-1)]-count[j-1];
                cout<<"当前分母"<<i<<"的结果："<<"j="<<j<<":"<<(j/i)*y*x<<endl;
                res=(res+(j/i)*y*x)%mod;
            }
        }
        return int(res);
    }

int main(){
    vector<int>nums={2,5,9};
    int res=sumOfFlooredPairs(nums);
    cout<<res<<endl;

    system("pause");
    return 0;
}