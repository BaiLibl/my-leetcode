#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool dfs(TreeNode* root,int num){
	if(root==NULL) return false;
	if(root->left==NULL&&root->right==NULL) return num==root->val?true:false;
	return dfs(root->left,num-(root->val))||dfs(root->right,num-(root->val));
}

bool hasPathSum(TreeNode* root, int sum) {
	  return dfs(root,sum);
}
/*
bool dfs(TreeNode* root,int sum){
	if(root==NULL)return false;
	if(root->left==NULL&&root->right==NULL&&(sum-(root->val)==0))return true; 
	else if(root!=NULL){
		if(dfs(root->left,sum-(root->val))||dfs(root->right,sum-(root->val)))return true;
	}
	return false;
}

bool hasPathSum(TreeNode* root, int sum) {
    if(root==NULL)return false;
	return dfs(root,sum);        
}

*/
int main(){
	return 0;
}
