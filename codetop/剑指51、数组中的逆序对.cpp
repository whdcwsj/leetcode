#include<bits/stdc++.h>
using namespace std;

//前面的数字大于后面的数字，构成一个逆序对

//1、归并的方法,O(log^n)
//计算逆序数在归并的过程中，利用排序后数组的有序性
//合并两个排序数组时，而每当遇到*左子数组当前元素>右子数组当前元素*
//意味着「左子数组当前元素 至 末尾元素」与「右子数组当前元素」构成了若干「逆序对」。

// int countnum;
// void merge(vector<int>& nums,int left,int mid,int right){
//     vector<int>temp(right-left+1);
//     int index=0;
//     int i=left;
//     int j=mid+1;
//     while(i<=mid && j<=right){
//         if(nums[i]<=nums[j]){
//             temp[index++]=nums[i++];
//         }else{
//             //统计逆序对
//             countnum+=(mid-i+1);
//             temp[index++]=nums[j++];
//         }
//     }
//     while(i<=mid){
//         temp[index++]=nums[i++];
//     }
//     while(j<=right){
//         temp[index++]=nums[j++];
//     }
//     for(int i=0;i<temp.size();i++){
//         nums[left+i]=temp[i];
//     }
// }

// void mergeSort(vector<int>& nums,int left,int right){
//     if(left<right){
//         int mid=left+(right-left)/2;
//         mergeSort(nums,left,mid);
//         mergeSort(nums,mid+1,right);
//         merge(nums,left,mid,right);
//     }
// }

// int reversePairs(vector<int>& nums){
//     countnum=0;
//     mergeSort(nums,0,nums.size()-1);
//     return countnum;
// }


// 2、树状数组
/* 
动态维护序列前缀和的数据结构，主要功能：
*单点更新：update(i,v)：把序列i位置的数加上一个值，本题v=1
*区间查询：query(i)：查询序列[1…i]区间的区间和，即i位置的前缀和
修改和查询的时间代价都是O(log n)，其中n为需要维护前缀和的序列的长度
*/

int reversePairs(vector<int>& nums){

}





int main(){
    vector<int>nums={7,5,6,4};
    int res=reversePairs(nums);
    cout<<res<<endl;

    system("pause");
    return 0;
}