#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //避免本身链表A既有重复节点
    unordered_set<ListNode*>visited;
    ListNode *wang=headA;
    while(wang!=NULL){
        visited.insert(wang);
        wang=wang->next;
    }
    wang=headB;
    while(wang!=NULL){
        if(visited.count(wang)){
            return wang;
        }
        wang=wang->next;
    }
    return NULL;
}


//浪漫做法
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
    ListNode*wang=headA;
    ListNode*si=headB;
    while(wang!=si){
        wang=(wang!=NULL?wang->next:headB);
        si=(si!=NULL?si->next:headA);
    }
    return wang;
}