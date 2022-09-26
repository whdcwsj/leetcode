#include<bits/stdc++.h>
using namespace std;


//最长重复子字符串(连续)
int find_length(string &a,string &b){
    int n=a.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            ans=max(ans,dp[i][j]);
        }
    }
    return ans;
}


int main(){
    int m;
    cin>>m;
    string s;
    string zhengque;
    vector<string>information(m,"");
    vector<string>chepai(m,"");
    vector<string>infor_answer(m,"");
    vector<string>chepai_answer(m,"");
    vector<int>score(m,0);

    // string wang="YZHEA163NB";
    // cout<<wang.substr(wang.size()-5,5)<<endl;
    // cout<<wang.substr(0,wang.size()-5)<<endl;

    for(int i=0;i<m;i++){
        cin>>s;
        chepai[i]=s.substr(s.size()-5,5);
        information[i]=s.substr(0,s.size()-5);
        cin>>zhengque;
        chepai_answer[i]=zhengque.substr(zhengque.size()-5,5);
        infor_answer[i]=zhengque.substr(0,zhengque.size()-5);
    }

    int temp_score;
    for(int i=0;i<m;i++){
        temp_score=0;
        // cout<<information[i]<<endl;
        // cout<<infor_answer[i]<<endl;
        //颜色
        char shibie_color=information[i][0];
        char real_color=infor_answer[i][0];
        if(shibie_color==real_color){
            temp_score+=2;
        }
        //位置
        string shibie_weizhi=information[i].substr(1,information[i].size()-1);
        string real_weizhi=infor_answer[i].substr(1,infor_answer[i].size()-1);
        // cout<<shibie_weizhi<<endl;
        // cout<<real_weizhi<<endl;
        if((strcmp(shibie_weizhi.c_str(),real_weizhi.c_str()))==0){
            temp_score+=3;
        }
        // cout<<"wang:"<<temp_score<<endl;
        //号码
        // cout<<chepai[i]<<endl;
        // cout<<chepai_answer[i]<<endl;
        int id_score=find_length(chepai[i],chepai_answer[i]);
        // cout<<"haoma:"<<id_score<<endl;
        temp_score+=id_score;
        score[i]=temp_score;
        temp_score=0;
    }

    double si=0.0; 
    for(int i=0;i<m;i++){
        si+=score[i];
    }
    si=si*1.0*100/(m*10);
    cout<<fixed<<setprecision(2)<<si<<"%"<<endl;



    system("pause");
    return 0;
}