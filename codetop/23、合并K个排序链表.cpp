#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode*next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x,ListNode*next):val(x),next(next){}
};

//这样时间复杂度超标，O(NK)
//多个指针指向多个子链表
ListNode* mergeKLists(vector<ListNode*>& lists){
    ListNode*head=new ListNode(-1);
    ListNode*wang=head;
    int k=lists.size();
    while(true){
        int minid=-1;
        ListNode*temp=NULL;
        for(int i=0;i<k;i++){
            if(lists[i]==NULL){
                continue;
            }
            if(temp=NULL || temp->val<lists[i]->val){
                minid=i;
                temp=lists[i];
            }
        }
        if(minid==-1){
            break;
        }
        wang->next=temp;
        wang=wang->next;
        lists[minid]=lists[minid]->next;
    }
    return head->next;
}

//归并方法