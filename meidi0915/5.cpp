#include<bits/stdc++.h>
using namespace std;


string long_zichaun(string s){
    int n=s.size();
    int maxlength=INT_MIN;
    //记录
    int start=0;
    int end=0;
    //2n-1
    for(int i=0;i<2*n-1;i++){
        int left=i/2;
        int right=i/2+i%2;
        while(left>=0 && right<n && s[left]==s[right]){
            //跳出判断
            if(right-left+1>maxlength){
                maxlength=right-left+1;
                start=left;
                end=right;
            }
            left--;
            right++;
        }
    }
    return s.substr(start,end-start+1);
}


int main(){
    string input="babad";
    string res=long_zichaun(input);
    cout<<res<<endl;

    system("pause");
    return 0;

}