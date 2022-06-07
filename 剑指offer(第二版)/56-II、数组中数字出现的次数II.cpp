#include<bits/stdc++.h>
using namespace std;


//因为数组中只有一个数出现了一次，那么各个二进制位为1的个数%3便能求出这个数哪些位置为1，最后再将其转换为十进制
int singleNumber(vector<int>& nums) {
    //0-31，共32位
    vector<int>bits(32,0);
    for(int i=0;i<nums.size();i++){
        int j=0;
        while(nums[i]){
            bits[j]+=nums[i]%2;
            nums[i]/=2;
            j++;
        }
    }
    int res=0;
    //将二进制转为十进制
    //(1<<i)就相当于2^i次方
    for(int i=0;i<32;i++){
        res+=(bits[i]%3)*(1<<i);
    }
    return res;
}



int main(){
    vector<int>nums = {9,1,7,9,7,9,7};
    int ans=singleNumber(nums);
    cout<<ans<<endl;

    system("pause");
    return 0;
}