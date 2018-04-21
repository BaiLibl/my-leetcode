#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode* head) {
	if(head==NULL||head->next==NULL)return head;
	ListNode* newhead=head;
	ListNode* tmp=head->next;
	newhead->next=NULL;//�Ͽ����� 
	
	while(tmp){
		ListNode* nextnode=tmp->next;
		ListNode* p = NULL;//������ǰһ����� 
		ListNode* q = newhead;//����λ�� 
		while(q&&tmp->val>q->val){
			p=q;
			q=q->next;
		}
		if(p==NULL){
			tmp->next=newhead;
			newhead = tmp;
		}else{
			tmp->next=q;
			p->next= tmp;
		}
		tmp = nextnode;
	}
	return newhead;
	        
}

int main(){
	return 0;
}
