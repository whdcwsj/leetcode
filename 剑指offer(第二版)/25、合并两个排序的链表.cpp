#include<bits/stdc++.h>
using namespace std;


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };



ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode*wang=new ListNode(-1);
    ListNode*head=wang;
    while(l1 && l2){
        if(l1->val<=l2->val){
            wang->next=l1;
            l1=l1->next;
        }else{
            wang->next=l2;
            l2=l2->next;
        }
        wang=wang->next;
    }
    while(l1){
        wang->next=l1;
        l1=l1->next;
        wang=wang->next;
    }
    while(l2){
        wang->next=l2;
        l2=l2->next;
        wang=wang->next;
    }
    return head->next;
}