#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;



bool isValid(const string& s,int start,int end);

//判断某个分段ip地址是否有效
bool isValid(const string& s,int start,int end){
        if(start>end) return false;
        // 0开头数字不合法，但是单独0可以
        if(s[start]=='0' && start!=end) return false;
        int res = stoi(s.substr(start,end-start+1));
        if(res<0 || res>255) return false;
        return true;
    }

// pointNUm表示添加逗点个数
void backtracking(string&s,int startIndex,int pointNum, vector<string>&res){
        //终止条件
        if(pointNum==3){
            if(isValid(s,startIndex,s.size()-1)){
                res.push_back(s);
            }
            return;
        }
        for(int i=startIndex;i<s.size();i++){
            if(isValid(s,startIndex,i)){
                // 符合要求，移一个位置插入逗点
                s.insert(s.begin()+i+1,'.');
                pointNum++;
                //新加入了一个逗点，从i+1开始
                backtracking(s,i+2,pointNum,res);
                pointNum--; //回溯
                s.erase(s.begin()+i+1);
            }else{
                //不满足要求，直接结束本层for循环
                break;
            }
        }
    }


vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.size()>12) return res;
        backtracking(s,0,0,res);
        return res;
    }


int main(){
    string input = "101023";
    vector<string>res;
    res=restoreIpAddresses(input);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}