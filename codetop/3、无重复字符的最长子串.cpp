#include<bits/stdc++.h>
using namespace std;

//注意s由英文字母、数字、符号和空格组成
int lengthOfLongestSubstring(string s){
    if(s.size()==0) return 0;
    if(s.size()==1) return 1;
    map<char,int>wang;
    int start=0;
    int maxlength=INT_MIN;
    for(int i=0;i<s.size();i++){
        wang[s[i]]++;
        if(wang[s[i]]>1){
            int pos=s.find_first_of(s[i],start);
            //cout<<"pos="<<pos<<endl;
            for(int j=start;j<=pos;j++){
                wang[s[j]]--;
            }
            start=pos+1;
        }else{
            maxlength=max(maxlength,i-start+1);
        }
    }
    return maxlength;
}


// int lengthOfLongestSubstring(string s){
//     if(s.size()==0) return 0;
//     unordered_set<char>wang;
//     int maxlength=INT_MIN;
//     int left=0;
//     for(int i=0;i<s.size();i++){
//         while(wang.find(s[i])!=wang.end()){
//             wang.erase(s[left]);
//             left++;
//         }
//         maxlength=max(maxlength,i-left+1);
//         wang.insert(s[i]);
//     }
//     return maxlength;
// }

int main(){
    string s="tmmzuxt";
    int num=lengthOfLongestSubstring(s);
    cout<<num<<endl;

    system("pause");
    return 0;
}