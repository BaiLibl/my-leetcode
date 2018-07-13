#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void flatten(TreeNode* root) {
   //�������ֵΪ�յ������һ���ֱ�Ӳ������������ٴ���һ����
   TreeNode* cur = root;
   while(cur!=NULL){
		if(cur->left){
			TreeNode* node = cur->left;
			while(node->right)node=node->right;
			node->right = cur->right;
			cur->right = cur->left;
			cur->left = NULL;
		}
		cur=cur->right;
   } 
    
}

int main(){
	return 0;
}
