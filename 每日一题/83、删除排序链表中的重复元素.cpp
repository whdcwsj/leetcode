#include<bits/stdc++.h>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};



ListNode* deleteDuplicates(ListNode* head) {
    if(!head) return NULL;
    ListNode*cur=head;
    while(cur && cur->next){
        if(cur->val==cur->next->val){
            ListNode*temp=cur->next;
            cur->next=temp->next;
            delete temp;
        }else{
            cur=cur->next;
        }
    }
    return head;
}