#include<bits/stdc++.h>
using namespace std;


// 这样dp一定会超时
// int count_time(vector<int>jiqiren, vector<int>&time){
//     int res=INT_MIN;
//     int n=jiqiren.size();
//     int m=time.size();
//     int id=0;
//     for(int i=0;i<n;i++){
//         if(jiqiren[0]!=0){
//             res=INT_MAX;
//             break;
//         }
//         int temp=0;
//         if(i+1>=n){
//             temp=time[i]*(m-id);
//             res=max(res,temp);
//         }else{
//             temp=time[i]*(jiqiren[i+1]-id);
//             res=max(res,temp);
//             id+=jiqiren[i+1];
//         }
//     }
//     return res;
// }

// // int main(){
// //     vector<int>jiqiren={1};
// //     vector<int>time={7,5,3};
// //     int res=count_time(jiqiren,time);
// //     cout<<res<<endl;

// //     system("pause");
// //     return 0;
// // }


// int main(){
//     int n,b;
//     cin>>n>>b;
//     vector<int>dianli(n,0);
//     vector<int>time(n,0);
//     for(int i=0;i<n;i++){
//         cin>>dianli[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>time[i];
//     }
//     // 特殊情况
//     if(dianli[0]>b){
//         cout<<-1<<endl;
//         return 0;
//     }
//     // 机器人，工作时间
//     vector<vector<pair<vector<int>,int>>>dp(n,vector<pair<vector<int>,int>>(b+1,{vector<int>{},INT_MAX}));
//     //初始化
//     for(int i=0;i<=b;i++){
//         if(i>=dianli[0]){
//             dp[0][i].second=time[0]*n;
//             dp[0][i].first.push_back(0);
//         }
//     }
//     // b是容量，time是value
//     for(int i=1;i<n;i++){
//         for(int j=1;j<=b;j++){
//             if(j<dianli[i]){
//                 if(dp[i-1][j].second<dp[i][j-1].second){
//                     dp[i][j].second=dp[i-1][j].second;
//                     dp[i][j].first=dp[i-1][j].first;
//                 }else{
//                     dp[i][j].second=dp[i][j-1].second;
//                     dp[i][j].first=dp[i][j-1].first;
//                 }
//                 cout<<"change:"<<i<<" "<<j<<" "<<dp[i][j].second<<endl;
//             }
//             else{
//                 vector<int>jiqiren;
//                 jiqiren=dp[i-1][j-dianli[i]].first;
//                 jiqiren.push_back(i);
//                 int temp=count_time(jiqiren,time);
//                 if(i==1 && j==2) cout<<"time:"<<temp<<endl;
//                 if(temp<min(dp[i-1][j].second,dp[i][j-1].second)){
//                     dp[i][j].second=temp;
//                     sort(jiqiren.begin(),jiqiren.end());
//                     dp[i][j].first=jiqiren;
//                     cout<<"new_change:"<<i<<" "<<j<<" "<<dp[i][j].second<<endl;
//                 }else{
//                     if(dp[i-1][j].second<dp[i][j-1].second){
//                         dp[i][j].second=dp[i-1][j].second;
//                         dp[i][j].first=dp[i-1][j].first;
//                     }else{
//                         dp[i][j].second=dp[i][j-1].second;
//                         dp[i][j].first=dp[i][j-1].first;
//                     }
//                 }
//             }
//         }
//     }
//     for(int i=0;i<=b;i++){
//         cout<<dp[n-1][i].second<<endl;
//     }



//     system("pause");
//     return 0;
// }



// 暴力dp很明显过不去
// 考虑二分总时间
// check的时候根据当前二分出来的时间限制做背包，求出在当前最大时间限制下需要的最少能量，最后和总能量限制比较
int n, M;

bool check(int n, int mid, vector<int>&p, vector<int>&t){
    vector<int> dp(n + 2, 1e9);
    dp[n + 1] = 0;
    for (int i = n; i >= 1; -- i) {
        for (int j = n + 1; j > i; -- j) {
            if (t[i] * (j - i) <= mid) {
                dp[i] = min(dp[i], dp[j] + p[i]);
            }
        }
    }
    return dp[1] <= M;
};
 
int main() {
    cin >> n >> M;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> p[i];
    vector<int> t(n + 1);
    for (int i = 1; i <= n; ++ i) cin >> t[i];
    if (p[1] > M) {
        cout << -1 << endl;
        return 0;
    }
    int l = 1, r = 1e9, ret = 1e9;


    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(n,mid,p,t)) {
            ret = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ret << endl;

    system("pause");
    return 0;
}