#include<bits/stdc++.h>
using namespace std;


int main(){
    string temp;
    vector<string>source;


    while(getline(cin,temp)){
        if(temp.empty()) break;
        source.push_back(temp);
    }
    
    // char c;
    // while(c=getchar()!=EOF){
    //     if(c=='\n'){
    //         source.push_back(temp);
    //         temp="";
    //     }else{
    //         temp+=c;
    //     }
    // }


    bool iszhushi=false;
    vector<string>res;
    string cur="";
    for(string s:source){
        int i=0;
        if(!iszhushi){
            cur="";
        }
        int n=s.size();
        while(i<n){
            if(!iszhushi && i<n-1 && s[i]=='/' && s[i+1]=='*'){
                iszhushi=true;
                i++;
            }else if(iszhushi && i<n-1 && s[i]=='*' && s[i+1]=='/'){
                iszhushi=false;
                i++;
            //本行直接结束
            }else if(!iszhushi && i<n-1 && s[i]=='/' && s[i+1]=='/'){
                break;
            }
            //加上剩余的代码部分
            else if(!iszhushi){
                cur+=s[i];
            }
            i++;
        }
        //空结果不输出
        if(!iszhushi && !cur.empty()){
            res.push_back(cur);
        }
    }
    for(int i=0;i<res.size();i++){
        cout<<res[i];
        if(i<res.size()-1) cout<<endl;
    }


    system("pause");
    return 0;
}