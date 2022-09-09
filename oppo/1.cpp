#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>nums;
    int target;
    string s;
    cin>>s;
    auto it=find(s.begin(),s.end(),']');
    s.erase(it);
    s.erase(0,1);
    stringstream ss(s);
    string temp;
    while(getline(ss,temp,',')){
        nums.push_back(stoi(temp));
    }
    int temp_n=nums.size();
    target=nums[temp_n-1];
    nums.pop_back();
    int n=nums.size();

    vector<vector<int>>res;
    sort(nums.begin(),nums.end());
    cout<<n<<endl;
    // cout<<target<<endl;
    // for(int i=0;i<n;i++){
    //     cout<<nums[i]<<endl;
    // }
    //a
    for(int i=0;i<n;i++){
        //去重
        if(i>0 && nums[i]==nums[i-1]) continue;
        int third=n-1;
        int mubiao=target-nums[i];
        for(int j=i+1;j<n;j++){
            //去重
            if(j>i+1 && nums[j]==nums[j-1]) continue;
            while(j<third && nums[j]+nums[third]>mubiao){
                third--;
            }
            //指针重合结束
            if(j==third) break;
            if(nums[j]+nums[third]==mubiao){
                res.push_back({nums[i],nums[j],nums[third]});
            }
        }
    }

    // for(int i=0;i<res.size();i++){
    //     for(int j=0;j<res[i].size();j++){
    //         cout<<res[i][j]<<endl;
    //     }
    //     cout<<"wang"<<endl;
    // }

    for(int i=0;i<res.size();i++){
        if(i==0) cout<<'[';
        for(int j=0;j<res[i].size();j++){
            if(j==0) cout<<'[';
            cout<<res[i][j];
            if(j<res[i].size()-1) cout<<',';
            if(j==res[i].size()-1) cout<<']';
        }
        if(i<res.size()-1) cout<<',';
        if(i==res.size()-1) cout<<']';
    }
    cout<<endl;



    system("pause");
    return 0;
}