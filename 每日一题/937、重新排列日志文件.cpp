#include<bits/stdc++.h>
using namespace std;


//对字母的进行排序
static bool cmp(const string& log1,const string& log2){
    int pos1=log1.find_first_of(" ");
    int pos2=log2.find_first_of(" ");
    if(log1.substr(pos1+1)!=log2.substr(pos2+1)){
        return log1.substr(pos1+1)<log2.substr(pos2+1);
    }
    return log1.substr(0,pos1)<log2.substr(0,pos2);
}

vector<string> reorderLogFiles(vector<string>& logs) {
    if(logs.size()<=1) return logs;
    vector<string>nums;
    vector<string>letter;
    for(int i=0;i<logs.size();i++){
        int index=logs[i].find_first_of(" ");
        if(isdigit(logs[i][index+1])){
            nums.push_back(logs[i]);
        }else{
            letter.push_back(logs[i]);
        }
    }
    sort(letter.begin(),letter.end(),cmp);
    cout<<"letter:"<<endl;
    for(int i=0;i<letter.size();i++){
        cout<<letter[i]<<endl;
    }
    cout<<"hahaha"<<endl;
    // vector.insert(pos,beg,end);
    letter.insert(letter.end(),nums.begin(),nums.end());
    return letter;
}




int main(){
    vector<string>logs={"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
    vector<string>res=reorderLogFiles(logs);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }

    system("pause");
    return 0;
}