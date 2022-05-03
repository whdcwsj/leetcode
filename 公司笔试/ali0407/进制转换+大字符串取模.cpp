#include<bits/stdc++.h>
using namespace std;
//大数的取模运算

const long long maxnum=10e9+7;


//要从前往后做，这个做法非常巧妙
long long getNum(string &s,int jinzhi){
    long long res=0;
    for(char &c:s){
        res*=jinzhi;
        if(isdigit(c)){
            res=(res+c-'0')%maxnum;
        }else{
            res=(res+c-'A'+10)%maxnum;
        }
    }
    return res;
}


int main(){
    string s;
    cin>>s;
    //计算最高为多少进制
    int maxjinzhi=0;
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])) {
            maxjinzhi=max(s[i]-'0'+1,maxjinzhi);
        }
        else if(isupper(s[i])){
            maxjinzhi=max(s[i]-'A'+11,maxjinzhi);
        }
    }
    if(maxjinzhi==1){
        cout << 0 << endl;
        return 0;
    }
    // cout<<maxjinzhi<<endl;

    vector<long long>wang;
    for(int i=maxjinzhi;i<=16;i++){
        wang.push_back(getNum(s,i)%maxnum);
    }

    for(auto p: wang) cout << p << endl;

    system("pause");
    return 0;
}


// #define MOD 1000000007

// long long getNum(string &s, int x) {
//     //要空值res不能超过MOD，边乘边除
//     long long res = 0;
//     for (char c: s) {
//         res *= x;
//         if (c >= '0' && c <= '9') {
//             res = (res + c - '0') % MOD;
//         } else {
//             res = (res + c - 'A' + 10) % MOD;
//         }
//     }
//     return res;
// }

// int main() {
//     //计算进制
//     int x = 0;
//     string s;
//     cin >> s;
//     set<long long> st;
//     for (auto &c: s) {
//         if (c >= '0' && c <= '9') {
//             x = max(x, c - '0' + 1);
//         } else if (c >= 'A' && c <= 'F') {
//             x = max(x, c - 'A' + 11);
//         }
//     }
//     if (x == 1) {
//         cout << 0 << endl;
//         return 0;
//     }
//     for (; x <= 16; x++) {
//         st.insert(getNum(s, x) % MOD);
//     }
//     for (auto p: st)
//         cout << p << endl;

//     system("pause");
//     return 0;
// }