#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

//方法一，最后反转
vector<int> reversePrint(ListNode* head){
    vector<int>res;
    while(head!=NULL){
        res.push_back(head->val);
        head=head->next;
    }
    reverse(res.begin(),res.end());
    return res;
}

//方法二：用stack来反转元素
vector<int> reversePrint(ListNode* head){
    if(head==NULL) return {};
    stack<int>s;
    while(head!=NULL){
        s.push(head->val);
        head=head->next;
    }
    int n=s.size();
    vector<int>res(n);
    for(int i=0;i<n;i++){
        res[i]=s.top();
        s.pop();
    }
    return res;
}