#include<bits/stdc++.h>
using namespace std;


//暴力做法的话，需要验证每个字符串的有效性
bool valid(const string& str) {
        int balance = 0;
        for (char c : str) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }



vector<string>res;

//left和right分别记录左右括号的数量
void backtracking(string&path,int n,int left,int right){
    if(path.size()==2*n){
        res.push_back(path);
    }
    //保证先左后右
    if(left<n){
        path.push_back('(');
        backtracking(path,n,left+1,right);
        path.pop_back();
    }
    if(right<n){
        path.push_back(')');
        backtracking(path,n,left,right+1);
        path.pop_back();        
    }
}



//只要保证添加过程中左括号和右括号不失衡就行
vector<string> generateParenthesis(int n) {
    string path;
    backtracking(path,n,0,0);
    return res;
}



int main(){
    int n = 3;
    vector<string>ans=generateParenthesis(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    system("pause");
    return 0;
}