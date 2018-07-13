#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector< vector<int> > res;

void dfs(TreeNode* root,int num,vector<int> tmp){
	if(root==NULL) return;
	tmp.push_back(root->val);
	if(root->left==NULL&&root->right==NULL){
		if(root->val==num)res.push_back(tmp);
	}else{
		dfs(root->left,num-(root->val),tmp);
		dfs(root->right,num-(root->val),tmp);	
	}
}

vector< vector<int> > pathSum(TreeNode* root, int sum) {
	if(root==NULL)return res;
	vector<int> tmp;
	dfs(root,sum,tmp);
	return res;        
}

int main(){
	return 0;
}
