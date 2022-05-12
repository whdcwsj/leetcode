#include<bits/stdc++.h>
using namespace std;


int minDeletionSize(vector<string>& strs) {
    //列字符串的长度
    int n=strs.size();
    if(n==1) return 0;
    //列字符串的个数
    int m=strs[0].size();
    int res=0;
    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            if(strs[j][i]-strs[j-1][i]<0){
                res++;
                break;
            }
        }
    }
    return res;
}


int main(){
    vector<string> strs = {"zyx","wvu","tsr"};
    int ans=minDeletionSize(strs);
    cout<<ans<<endl;

    system("pause");
    return 0;
}