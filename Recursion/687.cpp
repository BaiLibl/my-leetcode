#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int res = 0;
int path(TreeNode* root,int v){
	if(root==NULL)return 0;
	int llen,rlen;
	if(root->val==v){
		llen = path(root->left,v);
		rlen = path(root->right,v);
		res = max(res,llen+rlen);
		return 	max(llen,rlen)+1;
	}else{
		llen = path(root->left,root->val);
		rlen = path(root->right,root->val);
		res = max(res,llen+rlen);
		return 0;
	}
}

int longestUnivaluePath(TreeNode* root){
	if(root==NULL||(root->left==NULL&&root->right==NULL))return 0;
	int i=path(root,root->val);
	return res;
	
}

int main(){
	return 0;
}
