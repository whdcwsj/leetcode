#include<bits/stdc++.h>
using namespace std;


vector<int>nums;
//不需要完全的快排，部分就行
//返回第count大的数字
int randomPartition(vector<int>&a,int left,int right){
    //以最右边的最为边界值，这样将小的数值在左边堆叠
    int temp=rand()%(right-left+1)+left;
    swap(a[right],a[temp]);
    int pivot=a[right];
    int count=left;
    for(int i=left;i<right;i++){
        if(a[i]<=pivot){
            swap(a[count++],a[i]);
        }
    }
    swap(a[count],a[right]);
    return count;
}

//查询第index大的元素
int quickSort(vector<int>&a,int left,int right,int index){
    int temp=randomPartition(a,left,right);
    if(temp==index){
        return a[index];
    }else{
        return temp<index?quickSort(a,temp+1,right,index):quickSort(a,left,temp-1,index);
    }
}

int main(){
    srand(time(0));
    nums={3,76,54,1,87,90,5};
    int k=3;
    int res=quickSort(nums,0,nums.size()-1,nums.size()-k);

    cout<<res<<endl;

    system("pause");
    return 0;
}