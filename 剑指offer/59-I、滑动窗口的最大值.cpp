#include<bits/stdc++.h>
using namespace std;

// 单调队列
//1、使用双端队列,在其中存储每个数字对应的index
// vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int>res;
//     deque<int>q;
//     //保证每次最大数字处于队头位置
//     for(int i=0;i<nums.size();i++){
//         //超出作用范围的话,[-3,1,2]，队头删除
//         if(!q.empty() && i-k==q.front()) q.pop_front();
//         //队尾添加数字对应的index,可能会删除多次
//         while(!q.empty() && nums[i]>nums[q.back()]) q.pop_back();
//         q.push_back(i);
//         //记录结果
//         if(i>=k-1) res.push_back(nums[q.front()]);
//     }
//     return res;
// }


//2、优先队列
vector<int> maxSlidingWindow(vector<int>& nums, int k){
    int n=nums.size();
    if(n==0) return vector<int>();
    priority_queue<pair<int,int>>q;
    for(int i=0;i<k;i++){
        q.push({nums[i],i});
    }
    vector<int>res={q.top().first};
    for(int i=k;i<n;i++){
        q.push({nums[i],i});
        //这里一定要用while
        while(q.top().second<=i-k) q.pop();
        res.push_back(q.top().first);
    }
    return res;
}




int main(){
    vector<int>nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int>ans=maxSlidingWindow(nums,k);
    for(auto&a:ans){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}