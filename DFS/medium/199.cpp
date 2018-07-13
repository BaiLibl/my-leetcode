#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//DFS+height
void dfs(TreeNode* root,vector<int>& res,int height){
	if(res.size()==height)res.push_back(root->val);
	if(root->right!=NULL){
		dfs(root->right,res,height+1);
	}
	if(root->left!=NULL){
		dfs(root->left,res,height+1);
	}
	
}
vector<int> rightSideView(TreeNode* root) {
	vector<int> res;
	if(root==NULL)return res;
	res.push_back(root->val);
	if(root->right!=NULL){
		dfs(root->right,res,1);
	}
	if(root->left!=NULL){
		dfs(root->left,res,1);
	}
	return res;
}

int main(){
	return 0;
}
