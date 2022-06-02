#include<bits/stdc++.h>
using namespace std;



//连续子区间和为target
//至少有两个数字
vector<vector<int>> findContinuousSequence(int target) {
    //左闭右开
    int left=1;
    int right=1;
    int sum=0;
    vector<vector<int>>res;

    //右边先扩，左边再减少
    while(left<= target/2){
        if(sum<target){
            sum+=right;
            right++;
        }
        else if(sum>target){
            sum-=left;
            left++;
        }else{
            vector<int>temp;
            for(int k=left;k<right;k++){
                temp.push_back(k);
            }
            res.push_back(temp);
            //左边界向右移动，继续寻找
            sum-=(left*2+1);
            left+=2;
        }
    }
    return res;
}



int main(){
    int target = 9;
    vector<vector<int>>ans=findContinuousSequence(target);
    cout<<"wang"<<endl;
    for(auto&a:ans){
        for(auto&b:a){
            cout<<b<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    system("pause");
    return 0;
}