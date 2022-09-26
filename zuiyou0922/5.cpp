#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<int>nums;
    string s;
    while(getline(cin,s,' ')){
        nums.push_back(stoi(s));
    }

    int n=nums.size();
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    cout<<1<<endl;
    system("pause");
    return 0;
}