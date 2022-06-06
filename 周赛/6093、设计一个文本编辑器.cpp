#include<bits/stdc++.h>
using namespace std;


//常规做法
string text;
int cursor=0;

TextEditor() {

}
    
void addText(string text) {
    this->text.insert(cursor,text);
    cursor+=text.size();
}
    
int deleteText(int k) {
    int actual=min(k,cursor);
    text.erase(max(cursor-k,0),actual);
    cursor-=actual;
    return actual;
}
    
string cursorLeft(int k) {
    cursor-=k;
    if(cursor<0) cursor=0;
    return text.substr(max(0,cursor-10),min(10,cursor));
}
    
string cursorRight(int k) {
    cursor+=k;
    if(cursor>text.size()) cursor=text.size();
    return text.substr(max(0,cursor-10),min(10,cursor));
}



//2、双栈做法
    stack<char> l,r;

    TextEditor() {

    }
    
    void addText(string text) {
        for(char i: text) l.push(i);
    }
    
    int deleteText(int k) {
        for(int i=0;i<k;i++){
            if(l.empty()) return i;
            l.pop();
        }
        return k;
    }
    
    string cursorLeft(int k) {
        while(k--){
            if(l.size()){
                r.push(l.top());
                l.pop();
            }
        }
        string s;
        for(int i=0;i<10;i++){
            if(l.size()) s += l.top(), l.pop();
        }
        reverse(s.begin(),s.end());
        for(char i: s) l.push(i);
        return s;
    }
    
    string cursorRight(int k) {
        while(k--){
            if(r.size()){
                l.push(r.top());
                r.pop();
            }
        }
        string s;
        for(int i=0;i<10;i++){
            if(l.size()) s += l.top(), l.pop();
        }
        reverse(s.begin(),s.end());
        for(char i: s) l.push(i);
        return s;
    }