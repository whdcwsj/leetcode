#include<bits/stdc++.h>
using namespace std;


//区间合并
set<pair<int,int>>st;

RangeModule() {

}
    
void addRange(int left, int right) {
    auto it=st.lower_bound({left,-2e9});
    while(it!=st.end()){
        if(it->second>right+1) break;
        left=min(left,it->second);
        right=max(right,it->first);
        st.erase(it++);
    }
    st.insert({right,left});
}
    
bool queryRange(int left, int right) {
    auto it=st.lower_bound({right,-2e9});
    if(it==st.end() || it->second>left) return false;
    return true;
}

//删除区间的话，先合并，再将大的切成两段小的
void removeRange(int left, int right) {
    addRange(left,right);
    auto it=st.lower_bound({left,-2e9});
    
    int newleft1=it->second;
    int newright1=left;
    if(newleft1<newright1){
        st.insert({newright1,newleft1});
    }
    int newleft2=right;
    int newright2=it->first;
    if(newleft2<newright2){
        st.insert({newright2,newleft2});
    }
    st.erase(it);
}