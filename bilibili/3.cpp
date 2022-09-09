#include<bits/stdc++.h>
using namespace std;


bool check(string s){
    bool flag=true;
    int n=s.size();
    int chazhi=stoi(s[1])-stoi(s[0]);
    for(int i=2;i<n;i++){
        if(chazhi>0 && s[i]=='9' && i<n-1){
            flag=false;
            break;
        }
        else if(stoi(s[i])-stoi(s[i-1])!=chazhi){
            flag=false;
            break;
        }
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
        bool s_flag=true;
        string s=code[i];
        int start=-1;
        for(int j=0;j<s.size();j++){
            if(isdigit(s[j])){
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
                    if(s_flag==false){
                        cout<<"no"<<endl;
                        break;
                    }
                }
            }
        }
        if(s_flag==true){
            cout<<"yes"<<endl;
        }
    }


    system("pause");
    return 0;
}