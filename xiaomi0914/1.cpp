#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>nums;
    string s;
    cin>>s;
    s.erase(s.size()-1,1);
    s.erase(0,1);
    //cout<<s<<endl;
    stringstream ss(s);
    string wang;
    while(getline(ss,wang,',')){
        nums.push_back(stoi(wang));
    }
    // for(auto&a:nums){
    //     cout<<a<<" ";
    // }
    int n;
    cin>>n;
    int x;
    cin>>x;

    //找子数组中，是否存在sum-x的子数组
    //处理前缀和
    int left=0;
    int right=left+1;
    int target=0;
    for(int i=0;i<n;i++){
        target+=nums[i];
    }
    int res=-1;
    target-=x;
    if(target==0){
        cout<<n<<endl;
    }

    int temp=nums[left]+nums[right];
    while(left<=right && right<n){
        if(temp==target){
            res=max(right-left+1,res);
        }
        if(temp<=target){
            right++;
            temp+=nums[right];
        }else if(temp>target){
            temp-=nums[left];
            left++;
        }
    }
    if(res==-1){
        cout<<res<<endl;
    }else{
        cout<<n-res<<endl;
    }

    system("pause");
    return 0;
}