#include<bits/stdc++.h>
using namespace std;


queue<int>q;
//记录最大数值
deque<int>d;

MaxQueue() {

}
    
int max_value() {
    if(d.empty()) return -1;
    return d.front();
}
    
void push_back(int value) {
    //比当前数字小的数字，删除掉
    while(!d.empty() && d.back()<value){
        d.pop_back();
    }
    d.push_back(value);
    q.push(value);
}
    
int pop_front() {
    if(q.empty()) return -1;
    int ans=q.front();
    if(ans==d.front()){
        d.pop_front();
    }
    q.pop();
    return ans;
}