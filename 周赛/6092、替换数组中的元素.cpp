#include<bits/stdc++.h>
using namespace std;


// unordered_map<int,int>record;
// unordered_map<int,int>wang;

// vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
//     for(auto &ope:operations){
//         if(!record.empty() && record.count(ope[0])){
//             record[ope[1]]=record[ope[0]];
//             record.erase(ope[0]);
//         }else{
//             record[ope[1]]=ope[0];
//         }
//     }
//     for(auto &re:record){
//         wang[re.second]=re.first;
//         cout<<re.second<<" "<<re.first<<" "<<endl;
//     }
//     // sort(nums.begin(),nums.end());
//     for(int i=0;i<nums.size();i++){
//         if(wang.count(nums[i])){
//             nums[i]=wang[nums[i]];
//         }
//     }
//     return nums;
// }



    //这样好像更合理一些些
    //用map记录每个nums[i]以及对应的位置i，不断进行更换即可
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        map<int,int> m;
        int n=nums.size(),i;
        for(i=0;i<n;i++)m[nums[i]]=i;
        for(auto &c:operations)
        {
            auto it=m.find(c[0]);
            m[c[1]]=it->second;
            m.erase(it);
        }
        vector<int> ans(n);
        for(auto &p:m)ans[p.second]=p.first;
        return ans;
    }




int main(){
    vector<int>nums = {1,2};
    vector<vector<int>>operations = {{1,3},{2,1},{3,2}};
    vector<int>ans=arrayChange(nums,operations);
    for(auto&a:ans){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}