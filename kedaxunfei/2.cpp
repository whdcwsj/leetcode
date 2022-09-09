#include<bits/stdc++.h>
using namespace std;


int main(){
    vector<string>mingan;
    string str;
    while(getline(cin,str)){
        if(str.empty()) break;
        mingan.push_back(str);
    }
    string word;
    getline(cin,word);
    int n=mingan.size();
    // cout<<"w:"<<word<<endl;
    // cout<<"n:"<<n<<endl;
    sort(mingan.begin(),mingan.end());

    for(int i=0;i<n;i++){
        if(word.find_first_of(mingan[i])!=string::npos){
            int index=word.find_first_of(mingan[i]);
            cout<<mingan[i]<<" "<<index<<" "<<mingan[i].size()+index-1<<endl;
        }
    }

    system("pause");
    return 0;
}