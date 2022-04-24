#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>nums;
    int num;
    while(n--){
        cin>>num;
        nums.push_back(num);
    }
    sort(nums.begin(),nums.end());
    int res=0;
    for(int i=0;i<nums.size();i++){
        res+=abs(nums[i]-(i+1));
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}