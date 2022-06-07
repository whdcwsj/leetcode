#include<bits/stdc++.h>
using namespace std;


//面试的时候，用双指针
string reverseWords(string s) {
    string res;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]==' '){
            continue;
        }
        int j=i;
        while(j>=0 && s[j]!=' ') j--;
        res.append(s.substr(j+1,i-j));
        res.append(" ");
        i=j;
    }
    //去除末尾空格
    if(!res.empty()) res.pop_back();
    return res;
}


int main(){
    string s="the sky is blue";
    string ans=reverseWords(s);
    cout<<ans<<endl;

    system("pause");
    return 0;
}