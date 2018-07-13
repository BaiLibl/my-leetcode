#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
 	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
bool isSame(TreeNode* left,TreeNode* right){
	if(left==NULL&&right==NULL){
		return true;
	}else if(left!=NULL&&right!=NULL){
		if(left->val==right->val){
			return isSame(left->left,right->left)&&isSame(left->right,right->right);
		}else{
			return false;
		}
	}else{
		return false;
	}
}
bool isSymmetric(TreeNode* root) {
	if(root==NULL)return false;
	return isSame(root->left,root->right);
}
/*
//2018-06-23
bool dfs(TreeNode* a,TreeNode* b){
	if(a==NULL&&b==NULL)return true;
	if((a!=NULL&&b==NULL)||(a==NULL&&b!=NULL)){
		return false;
	}
	if(a->val!=b->val){
		return false;
	}
	if(dfs(a->left,b->right)&&dfs(a->right,b->left))return true;
	return false;
} 

bool isSymmetric(TreeNode* root) {
	 if(root==NULL)return true;
	 if(root->left==NULL&&root->right==NULL)return true;
	 return dfs(root->left,root->right);      
}
*/
int main(){
	return 0;
}
