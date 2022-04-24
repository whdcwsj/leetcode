#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

//ACM模式链表的输入与输出
//链表的构造
struct ListNode{
    int val;
    ListNode*next;
    //构造函数
    ListNode(int n):val(n),next(nullptr){};
    ListNode(int n,ListNode*next):val(n),next(next){};
};

//链表的初始化
//假设链表的初始值在一个vector中
ListNode* createList(vector<int>&nums){
    int n=nums.size();
    if(n==0) return NULL;
    //记录头结点，便于最后返回
    ListNode*head=new ListNode(nums[0]);
    ListNode*cur=head;
    for(int i=1;i<n;i++){
        cur->next=new ListNode(nums[i]);
        cur=cur->next;
    }
    return head;
}

//需要对链表的vector进行赋值的话，通过string来赋值
vector<int>getVector(string input){
    vector<int>res;
    stringstream ss(input);
    string temp;
    //以逗号为分隔符
    while(getline(ss,temp,',')){
        res.push_back(stoi(temp));
    }
    return res;
}


//输出链表
void printList(ListNode*head)
{
	while(head)
	{
		cout<<head->val;
		if(head->next)
			cout<<"->";
		head=head->next;
	}
	cout << endl;
}

//操作以反转链表为例
ListNode* reverseList(ListNode* head){
    ListNode*wang=NULL;
    while(head){
        ListNode*temp=head->next;
        head->next=wang;
        wang=head;
        head=temp;
    }
    return wang;
}


int main(){

    // 第一种输入
    vector<int>numval={1,2,3,4,5,6};

    //第二种输入
    // string input;
    // cin>>input;
    // vector<int>numval=getVector(input);

    //第三种输入
    // int a;
    // vector<int>numval;
    // //这样cin代码上可以，但是本地只能通过ctrl+z来结束
    // while(cin>>a){
    //     numval.push_back(a);
    //     if(cin.get()=='\n') break;
    // }

    //创建链表
    ListNode*head=createList(numval);

    //链表处理
    ListNode*newhead=reverseList(head);

    //输出链表
    printList(newhead);


	system("pause");
	return 0;
}