#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int count;
    int num;
    set<int>nums;
    while(cin>>n){
        count=n;
        nums.clear();
        while(count--){
            cin>>num;
            nums.insert(num);
        }
        for(auto a:nums) cout<<a<<endl;
    }
    

    // system("pause");
    return 0;
}