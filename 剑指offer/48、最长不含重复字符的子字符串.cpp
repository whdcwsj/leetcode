#include <bits/stdc++.h>
using namespace std;



int lengthOfLongestSubstring(string s) {
    int n=s.size();
    if(n<=1) return n;
    unordered_map<char,int>m;
    int maxLen=1;
    int i=0;
    int j=0;
    while(j<n){
        if(m.find(s[j])!=m.end() && i<=m[s[j]]){
            //缩小窗口
            i=m[s[j]]+1;
        }
        if(j-i+1>maxLen){
            maxLen=j-i+1;
        }
        //记录位置
        m[s[j]]=j;
        j++;
    }
    return maxLen;
}




int main(){
    string s="abba";
    int ans=lengthOfLongestSubstring(s);
    cout<<ans<<endl;

    system("pause");
    return 0;
}