#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode* head) {
	ListNode* tmp=head;
	vector<int> res;
	if(head==NULL)return head;
	while(tmp!=NULL){
		res.push_back(tmp->val);
		tmp=tmp->next;
	} 
	sort(res.begin(),res.end());
	tmp=head;
	int i=0;
	while(tmp!=NULL){
		tmp->val = res[i];
		i++;
		tmp=tmp->next;
	}       
	return head;
}

    //��ĿҪ�󣺶������������  
    //����˼·���鲢������Merge  
    //�鲢����Ļ���˼���ǣ�
	//�ҵ�������м�ڵ㣬Ȼ��ݹ��ǰ�벿�ֺͺ�벿�ֱַ���й鲢�������������ź�����������Merge  
     class Solution {  
     public:  
         ListNode* sortList(ListNode* head) {  
             if (head == NULL || head->next == NULL)  return head;  
      
             //����ָ���ҵ��м�ڵ�  
             ListNode *fast = head, *slow = head;  
             //��ָ������������ָ����һ��
             while (fast->next != NULL && fast->next->next != NULL)  
             {  //ѭ������ fast->next != NULL && fast->next->next != NULL
                 fast = fast->next->next;  
                 slow = slow->next;  
             }  
             //�Ͽ�  
             fast = slow;  
             slow = slow->next;  
             fast->next = NULL;  
      
             ListNode *l1 = sortList(head); //ǰ�������  
             ListNode *l2 = sortList(slow); //��������  
             return mergeTwoLists(l1, l2);  
         }  
      
         //Merge Two Sorted Lists  
         ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){  
             ListNode dummy(-1); //��ʱͷָ�� 
             for (ListNode* p = &dummy; l1 != NULL || l2 != NULL; p = p->next)  
             {  
                 int val1 = l1 == NULL ? INT_MAX : l1->val;  
                 int val2 = l2 == NULL ? INT_MAX : l2->val;  
                 if (val1 <= val2)  
                 {  
                     p->next = l1;  
                     l1 = l1->next;  
                 }  
                 else  
                 {  
                     p->next = l2;  
                     l2 = l2->next;  
                 }  
             }  
             return dummy.next;  //��һ���㲻�� 
         }  
     };  

int main(){
	return 0;
}
