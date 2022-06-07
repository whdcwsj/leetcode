#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode*wang=head;
    while(k--){
        head=head->next;
    }
    while(head){
        wang=wang->next;
        head=head->next;
    }
    return wang;
}