#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* createTree(vector<int>& path,int start,int end){
	if(start>end){
		return NULL;
	}else if(start==end){
		return new TreeNode(path[start]);
	}else{
		int mid=start+(end-start)/2;
		TreeNode* root=new TreeNode(path[mid]);
		root->left = createTree(path,start,mid-1);
		root->right = createTree(path,mid+1,end);
		return root;
	}
}

TreeNode* sortedListToBST(ListNode* head) {
	if(head==NULL)return NULL;
	vector<int> path;
	ListNode* tmp=head;
	while(tmp){
		path.push_back(tmp->val);
		tmp=tmp->next;
	}        
	return createTree(path,0,path.size()-1);
}

TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        
        ListNode *curr = head;
        int count = 0;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        //分两段，head和后一段 从中间断开 
        int steps = count/2;
        ListNode *mid = head;
        ListNode *prev = NULL;
        for (int i=0; i<steps; i++) {
            prev = mid;
            mid = mid->next;
        }
        prev->next = NULL;
        
        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        return root;
}

int main(){
	return 0;
}
