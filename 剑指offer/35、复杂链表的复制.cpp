#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


Node* copyRandomList(Node* head) {
    if(!head) return head;
    Node*cur=head;
    //映射新的节点和旧的节点
    unordered_map<Node*,Node*>map;
    while(cur){
        map[cur]=new Node(cur->val);
        cur=cur->next;
    }
    cur=head;
    while(cur){
        map[cur]->next=map[cur->next];
        map[cur]->random=map[cur->random];
        cur=cur->next;
    }
    return map[head];
}