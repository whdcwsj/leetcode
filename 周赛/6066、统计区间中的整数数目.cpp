#include<bits/stdc++.h>
using namespace std;


//1、区间合并
//按右端点排序，pair默认第一关键字排序，所以第一个关键字存右端点，第二个关键字存右端点
typedef pair<int,int> pii;
int res=0;
set<pii>st;


CountIntervals() {
}
    
void add(int left, int right) {
    int l=left,r=right;
    //pair,要同时大于两个数字
    auto it=st.lower_bound(make_pair(left-1,-2e9));
    while(it!=st.end()){
        //后面没有和给定区间相交的区间了，就结束
        if(it->second>right+1) break;
        l=min(l,it->second);
        r=max(r,it->first);
        res-=it->first-it->second+1;
        st.erase(it++);
    }
    res+=r-l+1;
    st.insert(make_pair(r,l));
}
    
int count() {
    return res;
}



int main(){

    
    system("pause");
    return 0;
}