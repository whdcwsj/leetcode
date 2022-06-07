#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* reverseList(ListNode* head) {
    ListNode*wang=NULL;
    ListNode*cur=head;
    while(cur){
        auto temp=cur->next;
        cur->next=wang;
        wang=cur;
        cur=temp;
    }
    return wang;
}