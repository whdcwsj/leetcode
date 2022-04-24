#include<iostream>
#include<vector>
using namespace std;

// 求A中满足 "A[i]的字符串表示" 包含 "(i+1)的字符串表示"的个数

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        //输入元素
        for(auto &a:nums) cin>>a;
        int res=0;
        for(int i=0;i<n;i++){
            string sn=to_string(nums[i]);
            string si=to_string(i+1);
            if(sn.find(si)!=string::npos) res++;
        }
        cout<<res<<endl;

        system("pause");
        return 0;
    }
}