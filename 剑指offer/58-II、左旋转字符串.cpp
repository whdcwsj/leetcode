#include<bits/stdc++.h>
using namespace std;



//面试的时候不能够使用三个reverse，有点离谱
//可以自己定义reverse


// void myReverse(string&s,int left,int right){
//     while(left<=right){
//         swap(s[left],s[right]);
//         left++;
//         right--;
//     }
// }

// string reverseLeftWords(string s, int n) {
//     int wang=s.size()-1;
//     myReverse(s,0,n-1);
//     myReverse(s,n,wang);
//     myReverse(s,0,wang);
//     return s;
// }


//取余
string reverseLeftWords(string s, int n) {
        string res = string(s);
        int len = s.size();
        for(int i =0 ;i<len;++i){
            res[(i+len-n)%len]=s[i];
        }
        return res;
    }





int main(){
    string s = "abcdefg";
    int k = 2;
    string ans=reverseLeftWords(s,k);
    cout<<ans<<endl;

    system("pause");
    return 0;
}