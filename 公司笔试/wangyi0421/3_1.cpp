#include<bits/stdc++.h>
using namespace std;

/*
题目描述：一组数据，对数据中的每个元素只能进行两个操作：
1、变成大于x的最小质数
2、变成小于x的最大质数
最少需要多少次操作，可以变成相同的质数（不能是2）
*/

//题目分析，最终答案是凸函数（本题是下凸函数），因此可以采用二分方法

//存储数据
vector<int>nums;
//存储质数，每个质数对应的index
vector<int>zhishu;
map<int,int>zhitoid;
//大的质数和小的质数
vector<int>maxnum;
vector<int>minnum;
int n;


//判断是否质数
bool isPrime(int x){
    if(x<=1) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

//找区间内的质数
void judge(int x,int y){
    int index=0;
    for(int i=x;i<=y;i++){
        if(isPrime(i)){
            zhishu.push_back(i);
            zhitoid[i]=index++;
        }
    }
}

//计算数组中所有元素到当前质数的移动次数
long long calRes(int x){
    long long res=0;
    for(int i=0;i<n;i++){
        if(nums[i]>x){
            res+=abs(zhitoid[minnum[i]]-zhitoid[x])+1;
        }else{
            res+=abs(zhitoid[maxnum[i]]-zhitoid[x])+1;
        }
    }
    return res;
}

int main(){
    cin>>n;
    int num;
    nums.resize(n);
    for(int i=0;i<n;i++){
        cin>>num;
        nums[i]=num;
    }
    if(n==1){
        if(isPrime(nums[0]) && nums[0]!=2){
            cout<<0<<endl;
            return 0;
        }else if(nums[0]==1){
            cout<<2<<endl;
            return 0;
        }else{
            cout<<1<<endl;
            return 0;
        }
    }
    sort(nums.begin(),nums.end());
    judge(nums[0],nums[n-1]);

    //分别记录比每个数字大的质数和小的质数
    maxnum.resize(n);
    minnum.resize(n);
    for(int i=0;i<n;i++){
        for(int j=nums[i]-1;j>=0;j--){
            if(zhitoid.count(j)){
                minnum[i]=j;
                break;
            }
        }
        for(int j=nums[i]+1;j<nums.back();j++){
            if(zhitoid.count(j)){
                maxnum[i]=j;
                break;
            }
        }
    }

    unordered_map<int,long long>res;
    //开始二分查找
    int left=0;
    int right=zhishu.size()-1;
    while(left<=right){
        auto t=left+(right-left)/2;
        long long x;
        if(!res.count(zhishu[t])){
            res[zhishu[t]]=calRes(zhishu[t]);
        }
        x=res[zhishu[t]];
        bool flag;
        if(t==0){
            if(!res.count(zhishu[t+1])){
                res[zhishu[t+1]]=calRes(zhishu[t+1]);
            }
            flag= x>=res[zhishu[t+1]];

        }else{
            if(!res.count(zhishu[t-1])){
                res[zhishu[t-1]]=calRes(zhishu[t-1]);
            }
            flag= res[zhishu[t-1]]>=x;
        }
        if(flag){
            left=t+1;
        }else{
            right=t-1;
        }
    }
    cout<<res[zhishu[left-1]]<<endl;


    system("pause");
    return 0;
}