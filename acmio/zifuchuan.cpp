#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

// 多个测试用例，每个测试用例一行。
// 每行通过,隔开，有n个字符，n＜100
int main(){
    vector<string>wang;
    string s;
    while(cin>>s){
        stringstream ss(s); //定义流对象,复制s到ss
        string temp;
        //同时遇到换行符还是会结束
        while(getline(ss,temp,',')){
            wang.push_back(temp);
        }
        sort(wang.begin(),wang.end());
        for(int i=0;i<wang.size()-1;i++){
            cout<<wang[i]<<',';
        }
        cout<<wang[wang.size()-1]<<endl;
        wang.clear();
    }
    return 0;
}