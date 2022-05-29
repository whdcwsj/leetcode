#include<bits/stdc++.h>
using namespace std;



int rearrangeCharacters(string s, string target) {
    vector<int>wang(26,0);
    vector<int>res(26,0);
    int minNum=INT_MAX;
    for(auto&a:target){
        wang[a-'a']++;
    }
    for(auto&a:s){
        res[a-'a']++;
    }
    for(int i=0;i<26;i++){
        if(wang[i]!=0 && res[i]==0){
            minNum=0;
            break;
        }
        else if(wang[i]!=0 && res[i]!=0){
            if(res[i]<wang[i]){
                minNum=0;
                break;
            }else{
                minNum=min(minNum,res[i]/wang[i]);
            }
        }
    }
    return minNum;
}


int main(){
    string s = "ilovecodingonleetcode";
    string target = "code";
    int ans=rearrangeCharacters(s,target);
    cout<<ans<<endl;

    system("pause");
    return 0;
}