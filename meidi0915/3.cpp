#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    string ci;
    cin>>ci;
    stringstream ss(ci);
    string temp;
    unordered_set<string>word;
    while(getline(ss,temp,',')){
        // cout<<temp<<endl;
        word.insert(temp);
    }
    //dp
    int n=s.size();
    vector<int>dp(n+1,false);
    dp[0]=true;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(dp[j]){
                string wang=s.substr(j,i-j);
                if(word.find(wang)!=word.end()){
                    dp[i]=true;
                }
            }
        }
    }
    if(dp[n]==true){
        cout<<1<<endl;
    }else{
        cout<<0<<endl;
    }
    

    system("pause");
    return 0;
}