#include <bits/stdc++.h>
using namespace std;


char firstUniqChar(string s) {
    vector<bool>flag(26,0);
    char res=' ';
    for(int i=0;i<s.size();i++){
        if(flag[s[i]-'a']==0 && s.find_first_of(s[i],i+1)==string::npos){
            cout<<"i: "<<i<<" haha "<<endl;
            res=s[i];
            break;
        }else{
            flag[s[i]-'a']=1;
        }
    }
    return res;
}


int main(){
    //string s = "abaccdeff";
    string s = "cc";

    char ans=firstUniqChar(s);
    cout<<ans<<endl;

    system("pause");
    return 0;
}