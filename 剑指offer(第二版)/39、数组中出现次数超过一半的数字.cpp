#include<bits/stdc++.h>
using namespace std;


//1、hashmap:O(n)
int majorityElement(vector<int>& nums) {
    unordered_map<int,int>m;
    int maxnum=0;
    int digit=0;
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
        if(m[nums[i]]>maxnum){
            maxnum=m[nums[i]];
            digit=nums[i];
        }
    }
    return digit;
}

//2、sort函数：O(nlogn)

//3、摩尔投票法：核心理念为票数正负抵消 。此方法时间和空间复杂度分别为O(N)和O(1)
int majorityElement(vector<int>& nums){
    //众数
    int x=0;
    int votes=0;
    for(auto num:nums){
        if(votes==0) x=num;
        votes+= (num==x?:1:-1);
    }
    return x;
}


int main(){
    vector<int>nums={1, 2, 3, 2, 2, 2, 5, 4, 2};
    int ans=majorityElement(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}