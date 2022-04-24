#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;


vector<vector<int>>res;
vector<int>path;

void backtracking(vector<int>&visited,vector<int>& nums){
        //终止条件
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            // 数字使用过。则跳过
            if(visited[i]==1) continue;
            visited[i]=1;
            path.push_back(nums[i]);
            backtracking(visited,nums);
            path.pop_back();
            visited[i] = 0;
        }
    }

vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        //记录某个数字是否使用过，全排列不能有重复数字
        vector<int>visited(nums.size(),0);
        backtracking(visited,nums);
        return res;
    }

int main(){
    vector<int>input={1,2,3};
    vector<vector<int>>res;
    res=permute(input);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }
}