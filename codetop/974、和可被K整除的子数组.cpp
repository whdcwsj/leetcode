#include<bits/stdc++.h>
using namespace std;

//同余定理
//连续子数组
//前缀和+同余+哈希表
//时间复杂度O(n)
int subarraysDivByK(vector<int>& nums, int k){
    int n=nums.size();
    vector<int>pre(n+1);
    //以前缀和的模为键，出现次数为值
    //最开始要多初始化一个{0,1}，前缀和直接被k整除
    unordered_map<int,int>record={{0,1}};
    int res=0;
    for(int i=1;i<=n;i++){
        //加k避免有负数
        pre[i]=((nums[i-1]+pre[i-1])%k+k)%k;
        if(record.count(pre[i])){
            res+=record[pre[i]];
            //cout<<"res "<<res<<" i "<<i<<endl;
        }
        record[pre[i]]++;
    }
    return res;
}

int main(){
    vector<int>nums={4,5,0,-2,-3,1};
    int k=5;
    int num=subarraysDivByK(nums,k);
    cout<<num<<endl;

    system("pause");
    return 0;
}