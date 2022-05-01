#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


//计算每个字符对引力数值的贡献程度
long long appealSum(string s) {
    //很巧妙的方法
    ll res=0;
    //记录当前字符串结尾的引力值和
    ll sum=0;
    //记录字符最近出现的下标
    vector<int>pos(26,-1);
    for(int i=0;i<s.size();i++){
        int c=s[i]-'a';
        sum+=i-pos[c];
        res+=sum;
        pos[c]=i;
    }
    return res;
}

long long appealSum(String s) {
		Long index[] = new Long[26], sum = 0L;
		for (int i = 0; i < s.length(); i++) {
			index[s.charAt(i) - 'a'] = (long) i;
			for (int j = 0; j < 26; j++) {
				sum += index[j] == null ? 0 : 1 + index[j];
			}
		}
		return sum;
	}


int main(){

    string s = "abbca";
    long long haha=appealSum(s);
    cout<<haha<<endl;


    system("pause");
    return 0
}