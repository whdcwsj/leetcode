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
//1、多个指针指向多个子链表(K个)
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

//时间复杂度分析：K条链表的总结点数是N，平均每条链表有N/K个节点，因此合并两条链表的时间复杂度是O(N/K)
//从K条链表开始两两合并成1条链表，因此每条链表都会被合并logK次，因此K条链表会被合并K*logK次
//因此总共的时间复杂度是K*logK*N/K，即 O(NlogK)。

//2、分治合并方法，时间复杂度O(NlogK)
//先合并两个链表，再逐渐合并
ListNode*merge(ListNode*a,ListNode*b){
    ListNode*head=new ListNode(-1);
    ListNode*wang=head;
    while(a!=NULL && b!=NULL){
        if(a->val<b->val){
            wang->next=a;
            a=a->next;
        }else{
            wang->next=b;
            b=b->next;
        }
        wang=wang->next;
    }
    if(a!=NULL){
        wang->next=a;
    }else{
        wang->next=b;
    }
    return head->next;
}

ListNode*mergeSort(vector<ListNode*>&lists,int left,int right){
    if(left>right) return NULL;
    if(left==right) return lists[left];
    int mid=left+(right-left)/2;
    ListNode*m=mergeSort(lists,left,mid);
    ListNode*n=mergeSort(lists,mid+1,right);
    return merge(m,n);
}

ListNode* mergeKLists(vector<ListNode*>& lists){
    return mergeSort(lists,0,lists.size()-1);
}

// 3、优先队列，最小堆
// 这个方法和前两种方法的思路有所不同，需要维护当前每个链表没有被合并的元素的最前面一个,k个链表就最多有k个满足这样条件的元素
// 每次在这些元素里面选取val属性最小的元素合并到答案中。
// 在选取最小元素的时候，我们可以用优先队列来优化这个过程。


//这样是小顶堆
struct cmp{
    bool operator()(ListNode*a,ListNode*b){
        return a->val>b->val;
    }
}


ListNode* mergeKLists(vector<ListNode*>& lists){
    priority_queue<ListNode*,vector<ListNode*>,cmp>q;
    auto head=new ListNode(-1);
    auto wang=head;
    for(auto l:lists){
        if(l!=NULL) q.push(l);
    }
    while(!q.empty()){
        //堆顶的链表最小
        auto temp=q.top();
        q.pop();
        wang->next=temp;
        wang=wang->next;
        if(temp->next){
            q.push(temp->next);
        }
    }
    return head->next;
}