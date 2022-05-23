#include<bits/stdc++.h>
using namespace std;


//old方法
// vector<int> getLeastNumbers(vector<int>& arr, int k) {
//     int n=arr.size();
//     if(k>=n) return arr;
//     sort(arr.begin(),arr.end());
//     return vector<int>(arr.begin(),arr.begin()+k);
// }


//快排方法
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



vector<int> getLeastNumbers(vector<int>& arr, int k){
    int n=arr.size();
    if(k>=n) return arr;
    srand(time(0));
    int res=quickSort(arr,0,arr.size()-1,k);
    vector<int>wang;
    for(int i=0;i<k;i++){
        wang.push_back(arr[i]);
    }
    return wang;
}




int main(){
    vector<int>arr = {0,0,2,3,2,1,1,2,0,4};
    int k = 10;
    vector<int>ans=getLeastNumbers(arr,k);
    for(auto&a:ans){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}