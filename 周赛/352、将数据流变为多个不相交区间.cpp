#include<bits/stdc++.h>
using namespace std;


//判断某个数字是否出现
vector<bool>flag(10001,0);

SummaryRanges() {

}
    
void addNum(int val) {
    flag[val]=1;
}
    
vector<vector<int>> getIntervals() {
    vector<vector<int>>res;
    int start=-1;
    int end=-1;
    for(int i=0;i<10001;i++){
        if(flag[i]){
            //第一个数字出现
            if(start==-1){
                start=i;
                end=i;
            }
            //连续的数字，更改end取值
            else
            {
                end=i;
            }
        }else{
            //前面连续的数字出现
            if(start!=-1){
                vector<int>temp={start,end};
                res.push_back(temp);
                start=-1;
                end=-1;
            }
        }
    }
    //最后一些数字有值
    if(start!=-1){
        vector<int>temp={start,end};
        res.push_back(temp);
    }
    return res;
}