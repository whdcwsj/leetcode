#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;

int lastStoneWeight(vector<int>& stones) {
        //最大堆
        priority_queue<int>q;
        for(int stone:stones) q.push(stone);
        while(q.size()>1){
            int w1=q.top();
            q.pop();
            int w2=q.top();
            q.pop();
            if(w1>w2) q.push(w1-w2);
        }
        return q.empty()?0:q.top();
}

int main(){
    vector<int>input={2,7,4,1,8,1};
    int res=lastStoneWeight(input);
    // printf("res=%d",res);
    // printf("%d",res);
    print(res);
    return 0;
}