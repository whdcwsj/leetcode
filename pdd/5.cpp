#include<bits/stdc++.h>
using namespace std;

//测试次数
int n;

int main(){
    cin>>n;
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        cout<<floor(log2(num))+1<<endl;
    }

    system("pause");
    return 0;
}