#include<bits/stdc++.h>
using namespace std;


//直接循环判断会超时
//需要使用差分序列方法
int main(){
    int n,k;
    cin>>n>>k;
    if(n==1) return 0;
    int a[n][k];
    //记录所有的结果
    vector<vector<int>>wang;
    vector<int>temp;
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>a[i][j];
        }
        temp.clear();
        for(int j=1;j<k;j++){
            temp.push_back(a[i][j]-a[i][j-1]);
        }
        wang.push_back(temp);
    }
    // cout<<"wang"<<wang.size()<<endl;
    //记录序列个数
    map<vector<int>,int>count;
    for(auto a:wang) count[a]++;
    // cout<<count.size()<<endl;


    //处理零序列，先构造一个零序列
    vector<int>zero(k-1,0);
    int num_zero=0;
    if(count[zero]){
        int num=count[zero];
        num_zero+=num*(num-1)/2;
        count.erase(zero);
    }
    // cout<<num_zero<<endl;
    //其他序列
    int num_normal=0;
    for(auto item:count){
        for(int i=0;i<item.first.size();i++) zero[i]=-item.first[i];
        num_normal+=count[zero]*item.second;
    }
    // cout<<num_normal<<endl;
    cout<<num_zero+num_normal/2<<endl;
    system("pause");

    return 0;
}