#include <bits/stdc++.h>
using namespace std;

//归并排序
int countNum;

void merge(vector<int>& nums,int left,int mid,int right){
    vector<int>temp(right-left+1,0);
    int index=0;
    int i=left;
    int j=mid+1;
    while(i<=mid && j<=right){
        if(nums[i]<=nums[j]){
            temp[index++]=nums[i++];
        }else{
            //在这里记录逆序对数目
            countNum+=(mid-i+1);
            temp[index++]=nums[j++];
        }
    }
    while(i<=mid){
        temp[index++]=nums[i++];
    }
    while(j<=right){
        temp[index++]=nums[j++];
    }
    for(int k=0;k<temp.size();k++){
        nums[left+k]=temp[k];
    }
}


void mergeSort(vector<int>& nums,int left,int right){
    if(left<right){
        int mid=left+(right-left)/2;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
}

int reversePairs(vector<int>& nums) {
    countNum=0;
    mergeSort(nums,0,nums.size()-1);
    return countNum;
}



//2、树状数组
//没太看懂
// vector<int>tree;
// int n;

// static lowbit(int x){
//     return x&(-x);
// }

// //单点修改
// void update(int x){
//     while(x<=n){
//         tree[x]++;
//         x+=lowbit(x);
//     }
// }


// //区间查询
// int query(int x){
//     int res=0;
//     while(x){
//         res+=tree[x];
//         x-=lowbit(x);
//     }
//     return res;
// }

// int reversePairs(vector<int>& nums) {
//     n=nums.size();
//     tree.resize(n+1);
//     vector<int>temp=nums;
//     //离散化
//     sort(temp.begin(),temp.end());
//     for(int &num:nums){
//         num=lower_bound(temp.begin(),temp.end(),num)-temp.begin()+1;
//     }
//     int ans = 0;
//     for (int i = n - 1; i >= 0; --i) {
//         ans += query(nums[i] - 1);
//         update(nums[i]);
//     }
//     return ans;
// }



int main(){
    vector<int> nums={7,5,6,4};
    int ans=reversePairs(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}