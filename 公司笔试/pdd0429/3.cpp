#include<bits/stdc++.h>
using namespace std;

vector<string>word;
vector<string>wang;

bool compare(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        bool flag;
        cin>>n;
        word.clear();
        word.resize(n,"");
        for(int i=0;i<n;i++){
            cin>>word[i];
            if(compare(word[i])){
                flag=true;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }else{
            wang.clear();
            wang.resize(n,"");
            for(int i=0;i<n;i++){
                int num=0;
                for(int j=0;j<word[i].size();j++){
                    num*=10;
                    num+=(word[i][j]-'a'+1);
                }
                //cout<<num<<endl;
                wang[i]=to_string(num);
                //cout<<wang[i]<<endl;
            }
            //cout<<1111<<endl;
            sort(wang.begin(),wang.end());
            bool flag2=false;
            for(int i=0;i<wang.size()/2;i++){
                string temp=wang[i];
                reverse(temp.begin(),temp.end());
                auto it=find(wang.begin(),wang.end(),temp);
                if(it!=wang.end()){
                    flag2=true;
                }
            }
            if(flag2){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
    }

    system("pause");
    return 0;
}