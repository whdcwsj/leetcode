#include<bits/stdc++.h>
using namespace std;


bool check(string s){
    bool flag=true;
    int n=s.size();
    int chazhi=(s[1]-'0')-(s[0]-'0');
    if(chazhi==-1 || chazhi==1){
        for(int i=2;i<n;i++){
            if(chazhi>0 && s[i]=='9' && i<n-1){
                flag=false;
                break;
            }
            else if((s[i]-'0')-(s[i-1]-'0')!=chazhi){
                flag=false;
                break;
            }
        }
    }
    else{
        flag=false;
    }

    return flag;
}

int main(){
    int t;
    cin>>t;
    vector<string>code;
    for(int i=0;i<t;i++){
        string temp;
        cin>>temp;
        code.push_back(temp);
    }
    for(int i=0;i<t;i++){
        bool s_flag=false;
        string s=code[i];
        int start=-1;
        for(int j=0;j<s.size();j++){
            if(isdigit(s[j])){
                if(j<=s.size()-3){
                    start=j;
                    j++;
                    while(j<s.size()){
                        if(isdigit(s[j])){
                            j++;
                        }else{
                            break;
                        }
                    }
                    int end=j;
                    if(end-start>=3){
                        string wang=s.substr(start,end-start);
                        s_flag=check(wang);
                        if(s_flag==true){
                            cout<<"yes"<<endl;
                            break;
                        }
                    }
                }
            }
        }
        if(s_flag==false){
            cout<<"no"<<endl;
        }
    }


    system("pause");
    return 0;
}