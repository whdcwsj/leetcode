#include<bits/stdc++.h>
using namespace std;



//不使用除法
//分别计算上三角和下三角的数值
vector<int> constructArr(vector<int>& a) {
    int n=a.size();
    if(n<=1) return vector<int>{};
    vector<int>res(n,1);
    res[0]=1;
    //乘以下三角的组成部分
    for(int i=1;i<n;i++){
        res[i]=res[i-1]*a[i-1];
    }
    //乘以上三角的部分
    int temp=1;
    for(int i=n-2;i>=0;i--){
        temp*=a[i+1];
        res[i]*=temp;
    }
    return res;
}



int main(){
    vector<int>a={1,2,3,4,5};
    vector<int>ans=constructArr(a);
    for(auto &w:ans){
        cout<<w<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}