#include<bits/stdc++.h>
using namespace std;


//要求时间复杂度为 O(n) 且仅使用常量额外空间的算法解决此问题
//抽屉原理

//1、我的做法
vector<int> findDuplicates(vector<int>& nums) {
    int n=nums.size();
    vector<bool>flag(n,0);
    vector<int>res;
    for(int i=0;i<n;i++){
        if(flag[nums[i]]==true){
            res.push_back(nums[i]);
        }
        else if(flag[nums[i]]==false){
            flag[nums[i]]=true;
        }
    }
    return res;
}


//方法：交换法/抽屉原理
//“桶排序”的思想是“抽屉原理”，即“一个萝卜一个坑”
//8 个萝卜要放在 7 个坑里，则至少有 1 个坑里至少有 2 个萝卜。

//由于数组的下标范围是[0, n-1]，我们需要将数i放在数组中下标为i-1的位置
//如果i出现了两次，那么希望其中的一个i放在数组下标中为i-1的位置
//另一个i放置在任意「不冲突」的位置j。也就是说，数j+1没有在数组中出现过


//具体方法：
//我们对数组进行一次遍历。当遍历到位置i时
//nums[i]应该被放在位置nums[i]−1。因此交换num[i]和nums[nums[i]−1] 即可
//直到待交换的两个元素相等为止。


//每一次交换操作会使得至少一个元素被交换到对应的正确位置，因此交换的次数为O(n)
vector<int> findDuplicates(vector<int>& nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        //注意这里是while,大概率第一次的就换好几次了
        while(nums[i]!=nums[nums[i]-1]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    vector<int>res;
    for(int i=0;i<n;i++){
        if(nums[i]-1!=i){
            res.push_back(nums[i]);
        }
    }
    return res;
}




int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int>ans=findDuplicates(nums);
    for(auto &a:ans){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}