#include<bits/stdc++.h>
using namespace std;



int main(){
    int k=4;
    int n=7;
    vector<int>nums={1,4,7,2,5,6,3};
    //最小堆
    priority_queue<int,vector<int>,greater<int>>q;
    vector<int>res;
    for(int i=0;i<k;i++){
        q.push(nums[i]);
    }
    res.push_back(q.top());
    for(int i=k;i<n;i++){
        if(nums[i]<=q.top()){
            res.push_back(q.top());
            continue;
        }
        q.push(nums[i]);
        q.pop();
        res.push_back(q.top());
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    
    system("pause");
    return 0;
}