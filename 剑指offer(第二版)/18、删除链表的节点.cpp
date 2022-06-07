#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteNode(ListNode* head, int val) {
    ListNode*wang=new ListNode(-1);
    wang->next=head;
    ListNode*cur=head;
    if(cur->val==val){
        wang->next=cur->next;
        return wang->next;
    }
    while(cur->next){
        if(cur->next->val==val){
            cur->next=cur->next->next;
            break;
        }
        cur=cur->next;
    }
    return wang->next;
}