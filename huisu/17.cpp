#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;

void backtracking(string digits,vector<string>digittostring,int index,vector<string>&res,string s){
        // 终止条件
        // index与digits的数量相同
        if(index==digits.size()){
            res.push_back(s);
            return;
        }
        // 当前digits对应的int数字
        int num=digits[index]-'0';
        // 可选用字母
        string temp=digittostring[num];
        for(int i=0;i<temp.size();i++){
            s+=temp[i];
            backtracking(digits,digittostring,index+1,res,s);
            s.pop_back();
        }
    }

vector<string> letterCombinations(string digits) {
        vector<string> digittostring={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>res;
        string s;
        if(digits.empty()) return res;
        backtracking(digits,digittostring,0,res,s);
        return res;
    }

int main(){
    string input = "23";
    vector<string>res;
    res=letterCombinations(input);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
}