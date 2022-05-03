#include<bits/stdc++.h>
using namespace std;


struct work{
    int SLA;
    int score;
}works[110];

int main(){
    int n;
    cin>>n;
    int inputsla,inputscore;
    int num=0;
    while(n--){
        cin>>inputsla>>inputscore;
        works[num].SLA=inputsla;
        works[num].score=inputscore;
        num++;
    }
    map<int,vector<int>>record;
    for(int i=0;i<num;i++){
        record[works[i].SLA].push_back(works[i].score);
    }
    int res;
    for(int j=1;j<=7*105;j++){
        if(record[j].size()!=0){
            sort(record[j].begin(),record[j].end());
            res+=record[j][record[j].size()-1];
        }
    }
    cout<<res;

    system("pause");
    return 0;
}