#include<bits/stdc++.h>
using namespace std;

// int mod=1e9+7;
// //vector<int>path;
// int minNum=INT_MAX;
// long long res=0;


// void backtracking(vector<int>& strength,int startIndex,long long sum){
//     if(startIndex>=strength.size()){
//         return;
//     }
//     for(int i=startIndex;i<strength.size();i++){
//         //path.push_back(strength[i]);
//         if(strength[i]<minNum){
//             minNum=strength[i];
//         }
//         sum=(sum+strength[i])%mod;
//         res=(res+sum*minNum)%mod;
//         cout<<"i:"<<i<<endl;
//         cout<<"sum:"<<sum<<endl;
//         cout<<"res:"<<res<<endl;
//         backtracking(strength,startIndex+1,sum);
//         //回溯
//         if(sum-strength[i]<=0){
//             sum=mod-strength[i]+sum;
//         }else{
//             sum-=strength[i];
//         }
//     }
// }


// int totalStrength(vector<int>& strength) {
//     long long sum=0;
//     backtracking(strength,0,sum);
//     return res;
// }


//单调栈+前缀和
int totalStrength(vector<int>& strength){
    
}


int main(){
    vector<int>strength = {5,4,6};
    int ans=totalStrength(strength);
    cout<<ans<<endl;

    system("pause");
    return 0;
}