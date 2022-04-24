#include<bits/stdc++.h>
using namespace std;

int randomPartition(vector<int>& nums,int left,int right){
    int temp=rand()%(right-left+1)+left;
    swap(nums[temp],nums[right]);
    int pivot=nums[right];
    //记录左边有多少个数字比当前数字小
    int count=left;
    for(int i=left;i<right;i++){
        //小于等于都要放
        if(nums[i]<=pivot){
            swap(nums[count++],nums[i]);
        }
    }
    swap(nums[count],nums[right]);
    return count;
}

int quickSort(vector<int>& nums,int left,int right,int index){
    int temp=randomPartition(nums,left,right);
    if(temp==index){
        return nums[index];
    }else{
        return temp<index?quickSort(nums,temp+1,right,index):quickSort(nums,left,temp-1,index);
    }

}

int findKthLargest(vector<int>& nums, int k) {
    srand(time(0));
    int n=nums.size();
    int res=quickSort(nums,0,n-1,n-k);
    return res;
}

int main(){
    vector<int>nums={3,2,3,1,2,4,5,5,6};
    int a=4;
    int num=findKthLargest(nums,a);

    cout<<num<<endl;

    system("pause");
    return 0;
}