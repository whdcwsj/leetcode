#include<bits/stdc++.h>
using namespace std;


stack<int>inStack,outStack;

void in_to_out(){
    while(!inStack.empty()){
        outStack.push(inStack.top());
        inStack.pop();
    }
}


CQueue() {

}
    
void appendTail(int value) {
    inStack.push(value);
}
    
int deleteHead() {
    if(!outStack.empty()){
        int num=outStack.top();
        outStack.pop();
        return num;
    }else{
        in_to_out();
        if(!outStack.empty()){
             int num=outStack.top();
            outStack.pop();
            return num;
        }else{
            return -1;
        }
    }
}
