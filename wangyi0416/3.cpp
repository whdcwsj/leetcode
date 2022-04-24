#include<bits/stdc++.h>
using namespace std;

bool check(map<char,int>wang,int setnum){
    bool flag=true;
    for(int i=0;i<wang.size();i++){
        if(wang[i]>setnum){
            flag=false;
            break;
        }
    }
    return flag;
}


void backtracking(string ss,int size,int num,int left,int right,map<char,int>wang,int set){
    for(int i=left;i<=right;i++){
        wang[ss[i]]--;
    }
    if(check(wang,set)) num++;
    cout<<num<<endl;
    for(int i=left;i<=right;i++){
        wang[ss[i]]++;
    }
    if(right+1-left+1<=size-1){
        backtracking(ss,size,num,left,right+1,wang,set);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    map<char,int>wang;
    for(int i=0;i<s.size();i++){
        wang[s[i]]++;
    }
    int res;
    int size=s.size();
    for(int i=0;i<s.size();i++){
        int temp=0;
        backtracking(s,size,temp,i,i,wang,k);
        res+=temp;
    }
    cout<<res<<endl;

    system("pause");
    return 0;
}