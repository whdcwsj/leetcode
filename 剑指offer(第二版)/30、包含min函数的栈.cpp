#include <bits/stdc++.h>
using namespace std;

stack<int>s;
stack<int>min_s;
MinStack()
{
    while(!s.empty()) {
        s.pop();
    }
    while(!min_s.empty()) {
        min_s.pop();
    }
}

void push(int x)
{
    s.push(x);
    if(!empty(min_s)){
        min_s.push(x);
    }else{
        min_s.push(std::min(min_s.top(),x));
    }
}

void pop()
{
    s.pop();
    min_s.pop();
}

int top()
{
    return s.top();
}

int min()
{
    return min_s.top();
}


int main(){
    stack<int>s;
    cout<<s.top()<<endl;

    system("pause");
    return 0;
}