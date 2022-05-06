#include<bits/stdc++.h>
using namespace std;

int num;
queue<int>q;
RecentCounter() {
    num=0;
}
    
int ping(int t) {
    q.push(t);
    while(q.front()<t-3000){
        q.pop();
    }
    return q.size();
}