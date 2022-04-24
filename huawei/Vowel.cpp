#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    string temp;
    vector<string>wang;

    while(getline(ss,temp,' ')){
        wang.push_back(temp);
    }

    for(int i=0;i<wang.size();i++){
        for(char &c:wang[i]){
            if(c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u'){
                c-='a'-'A';
            }else if(c!='a' && c!='e'&& c!='i'&& c!='o'&& c!='u' && c!='A' && c!='E'&& c!='I'&& c!='O'&& c!='U'){
                if(isupper(c)){
                    c+='a'-'A';
                }
            }
        }
        cout<<wang[i];
        if(i<wang.size()-1) cout<<" ";
    }

    system("pause");
    return 0;
}