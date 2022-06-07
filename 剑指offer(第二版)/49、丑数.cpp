#include <bits/stdc++.h>
using namespace std;


int nthUglyNumber(int n) {
    vector<int>nums(1,1);
    int i2=0,i3=0,i5=0;
    while(nums.size()<n){
        int n2=nums[i2]*2;
        int n3=nums[i3]*3;
        int n5=nums[i5]*5;
        int num=min({n2,n3,n5});
        if(num==n2) i2++;
        if(num==n3) i3++;
        if(num==n5) i5++;
        nums.push_back(num);
    }
    return nums[n-1];
}




int main(){
    int n=10;
    int ans=nthUglyNumber(n);
    cout<<ans<<endl;

    system("pause");
    return 0;
}