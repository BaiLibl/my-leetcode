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
	//0����ȡroot
	//1����ȡroot
	vector<int> lres = dfs(root->left);
	vector<int> rres = dfs(root->right);
	res[0] = lres[1]+rres[1]+root->val;//0����ȡroot,��ȡ�����ӽڵ� 
	res[1] = max(lres[0],lres[1])+max(rres[0],rres[1]);//1����ȡroot,��ȡ�ɲ�ȡ�����ӽڵ� 
	return res; 
}

int rob(TreeNode* root) {
	if(root==NULL)return 0;
	vector<int> res = dfs(root);
	return max(res[0],res[1]);
}

/*
ֱ�ӵݹ� 
*/
int rob(TreeNode* root) {
    if(root==NULL)return 0;
	if(root->left==NULL&&root->right==NULL)return root->val;
	
	int notrob=rob(root->left)+rob(root->right);//��͵root 
	int isrob=root->val; //͵root����ֻ��Ͷ���ӽ�� 
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
