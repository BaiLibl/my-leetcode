#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int res=0;
void dfs(TreeNode* root,int sum){
	if(root==NULL){
		return;
	}
	sum=sum*10+root->val;
	if(root->right==NULL&&root->left==NULL){
		res+=sum;
        return;
	}
	dfs(root->left,sum);
	dfs(root->right,sum);
}

int sumNumbers(TreeNode* root) {
	if(root==NULL)return 0;
	dfs(root,0);
	return res;
}
int main(){
	return 0;
}
