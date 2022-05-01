#include<bits/stdc++.h>
using namespace std;


//1、自定义排序方法
/*
因此，本题本质上是要给出0,1,⋯,n−1的一个排列，并按照这个排列的顺序依次播种每一颗种子。
当我们播种第i颗种子时，如果统计出前面所有种子的播种时间之和prev，加上第i颗种子的播种时间p_i和生长时间 g_i
即为开花时间。所有开花时间中的最大值即为答案。
*/
//重点是推导过程

bool cmp(const pair<int,int>&a,const pair<int,int>&b){
    //升序排列
    return a.first>b.first;
}

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n=plantTime.size();
    vector<pair<int,int>>res(n);
    for(int i=0;i<n;i++){
        res.push_back({growTime[i],plantTime[i]});
    }
    sort(res.begin(),res.end(),cmp);
    //最终时间
    int final=0;
    //种植结束时间
    int prev=0;
    for(auto item:res){
        int gt=item.first;
        int pt=item.second;
        prev+=pt;
        final=max(final,prev+gt);
    }
    return final;
}

int main(){
    vector<int> plantTime = {1,2,3,2};
    vector<int> growTime = {2,1,2,1};
    int res=earliestFullBloom(plantTime,growTime);
    cout<<res<<endl;

    system("pause");
    return 0;
}