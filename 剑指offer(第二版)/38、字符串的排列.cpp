#include<bits/stdc++.h>
using namespace std;


vector<string>res;
string path;

void backtracking(string &s, vector<int>&visited){
    if(path.size()==s.size()){
        res.push_back(path);
        return;
    }
    for(int i=0;i<s.size();i++){
        //有相同字母出现
        if(i>0 && s[i-1]==s[i] && visited[i-1]==1) continue;
        //该字母已经访问
        if(visited[i]==1) continue;
        visited[i]=1;
        path.push_back(s[i]);
        backtracking(s,visited);
        //回溯
        path.pop_back();
        visited[i]=0;
    }
}

//可能有重复的字母，要去重
vector<string> permutation(string s) {
    sort(s.begin(),s.end());
    //记录某个字母是否被访问
    vector<int>visited(s.size(),0);
    backtracking(s,visited);
    return res;
}




int main(){
    string s = "abc";
    vector<string>ans=permutation(s);
    for(auto&a:ans){
        cout<<a<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}