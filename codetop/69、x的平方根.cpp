#include<bits/stdc++.h>
using namespace std;


//不能使用内置函数，只能二分查找
int mySqrt(int x){
    if(x<=1) return x;
    int left=0,right=x;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(mid<=x/mid){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return right;
}



int main(){
    int num=4;
    int res=mySqrt(num);
    cout<<res<<endl;

    system("pause");
    return 0;
}