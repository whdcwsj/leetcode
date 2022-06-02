#include<bits/stdc++.h>
using namespace std;


//两数之和,O(n)
// vector<int> twoSum(vector<int>& nums, int target) {
//     unordered_map<int,int>wang;
//     vector<int>res;
//     for(int i=0;i<nums.size();i++){
//         wang[nums[i]]=i;
//     }
//     for(int i=0;i<nums.size();i++){
//         int temp=target-nums[i];
//         //不能是一个数字使用两次
//         if(wang.count(temp) && wang[temp]!=i){
//             res.push_back(nums[i]);
//             res.push_back(temp);
//             break;
//         }
//     }
//     return res;
// }

// //双指针
// vector<int> twoSum(vector<int>& nums, int target){
//     int i=0;
//     int j=nums.size()-1;
//     int sum;
//     vector<int>res;
//     while(i<j){
//         sum=nums[i]+nums[j];
//         if(sum>target) j--;
//         else if(sum<target) i++;
//         else{
//             res.push_back(nums[i]);
//             res.push_back(nums[j]);
//             break;
//         }
//     }
//     return res;
// }


//有序的序列，二分查找，O(n*log^n)
vector<int> twoSum(vector<int>& nums, int target){
    for(int i=0;i<nums.size();i++){
        int temp=target-nums[i];
        //相当于排除了一班的工作量
        if(temp<nums[i]) break;
        int left=i+1;
        int right=nums.size()-1;
        //避免左边界超出范围
        if(left>=nums.size()) break;
        while(left<=right){
            if(nums[left]==temp || nums[right]==temp) return vector<int>{nums[i],temp};
            int mid=left+(right-left)/2;
            if(nums[mid]>temp){
                right=mid-1;
            }
            else if(nums[mid]<temp){
                left=mid+1;
            }
            else{
                return vector<int>{nums[i],temp};
            }
        }
    }
    return vector<int>();
}



int main(){
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>ans=twoSum(nums,target);
    for(auto&a:ans){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}