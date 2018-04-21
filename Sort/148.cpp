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

    //题目要求：对链表进行排序  
    //解题思路：归并排序，再Merge  
    //归并排序的基本思想是：
	//找到链表的中间节点，然后递归对前半部分和后半部分分别进行归并排序，最后对两个排好序的链表进行Merge  
     class Solution {  
     public:  
         ListNode* sortList(ListNode* head) {  
             if (head == NULL || head->next == NULL)  return head;  
      
             //快慢指针找到中间节点  
             ListNode *fast = head, *slow = head;  
             //快指针走两步，慢指针走一步
             while (fast->next != NULL && fast->next->next != NULL)  
             {  //循环条件 fast->next != NULL && fast->next->next != NULL
                 fast = fast->next->next;  
                 slow = slow->next;  
             }  
             //断开  
             fast = slow;  
             slow = slow->next;  
             fast->next = NULL;  
      
             ListNode *l1 = sortList(head); //前半段排序  
             ListNode *l2 = sortList(slow); //后半段排序  
             return mergeTwoLists(l1, l2);  
         }  
      
         //Merge Two Sorted Lists  
         ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){  
             ListNode dummy(-1); //暂时头指针 
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
             return dummy.next;  //第一个点不算 
         }  
     };  

int main(){
	return 0;
}
