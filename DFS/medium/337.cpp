#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> dfs(TreeNode* root){
	vector<int> res=vector<int>(2,0);
	if(root==NULL)return res;
	//0代表取root
	//1代表不取root
	vector<int> lres = dfs(root->left);
	vector<int> rres = dfs(root->right);
	res[0] = lres[1]+rres[1]+root->val;//0代表取root,不取左右子节点 
	res[1] = max(lres[0],lres[1])+max(rres[0],rres[1]);//1代表不取root,可取可不取左右子节点 
	return res; 
}

int rob(TreeNode* root) {
	if(root==NULL)return 0;
	vector<int> res = dfs(root);
	return max(res[0],res[1]);
}

/*
直接递归 
*/
int rob(TreeNode* root) {
    if(root==NULL)return 0;
	if(root->left==NULL&&root->right==NULL)return root->val;
	
	int notrob=rob(root->left)+rob(root->right);//不偷root 
	int isrob=root->val; //偷root，则只能投孙子结点 
	if(root->left){
		isrob+=rob(root->left->left)+rob(root->left->right);	
	}
	if(root->right){
		isrob+=rob(root->right->left)+rob(root->right->right);
	}
	return max(isrob,notrob);
}

int main(){
	return 0;
}
